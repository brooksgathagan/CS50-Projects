// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize multiplier infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    if (n < 1 || n > 100)
    {
        printf("Value must be between 1 and 100");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bfresize;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    bfresize = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, biresize;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    biresize = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Make copies of the declared fileheader & infoheader variables

    // determine new width and height in our new "resize" variables
    biresize.biHeight = bi.biHeight * n;
    biresize.biWidth = bi.biWidth * n;

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding2 = (4 - (biresize.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // declare new file size
    bfresize.bfSize = 54 + (biresize.biWidth * sizeof(RGBTRIPLE) + padding2) * abs(biresize.biHeight);
    biresize.biSizeImage = bfresize.bfSize - 54;


    // write outfile's BITMAPFILEHEADER, replacing first parameter with new address
    fwrite(&bfresize, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER, replacing first parameter with new address
    fwrite(&biresize, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int z = 0; z < n; z++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);


                // write RGB triple * n to outfile
                for (int k = 0; k < n; k++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

            fseek(inptr, padding, SEEK_CUR);

            // add padding
            for (int l = 0; l < padding2; l++)
                putc(0x00, outptr);


            //skip back to beginning of scanline
            if (z < n-1)
                fseek(inptr, -(bi.biWidth * sizeof(RGBTRIPLE) + padding), SEEK_CUR);

        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}