#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    char salt[3];

    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    for (int v = 0; v < 2; v++)
    {
        salt[v] = argv[1][v];
    }

    string charcycle = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ./";
    int length = strlen(charcycle);

    int jj = 0, kk = 0, ll = 0, ii = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            for (int k = 0; k < length; k++)
            {
                for (int l = 0; l < length; l++)
                {
                    for (int m = 0; m < length; m++)
                    {
                        if (ii < length)
                        {
                            char charlist1[2] = {charcycle[m], '\0'};
                            if (strcmp(crypt(charlist1, salt), argv[1]) == 0)
                            {
                                printf("%s\n", charlist1);
                                return 0;
                            }
                        }

                        if (ii >= length && jj < length)
                        {
                            char charlist2[3] = {charcycle[m], charcycle[l], '\0'};
                            if (strcmp(crypt(charlist2, salt), argv[1]) == 0)
                            {
                                printf("%s\n", charlist2);
                                return 0;
                            }
                        }

                        if (jj >= length && kk < length)
                        {
                            char charlist3[4] = {charcycle[m], charcycle[l], charcycle[k], '\0'};
                            if (strcmp(crypt(charlist3, salt), argv[1]) == 0)
                            {
                                printf("%s\n", charlist3);
                                return 0;
                            }
                        }

                        if (kk >= length && ll < length)
                        {
                            char charlist4[5] = {charcycle[m], charcycle[l], charcycle[k], charcycle[j], '\0'};
                            if (strcmp(crypt(charlist4, salt), argv[1]) == 0)
                            {
                                printf("%s\n", charlist4);
                                return 0;
                            }
                        }

                        if (ll >= length)
                        {
                            char charlist5[6] = {charcycle[m], charcycle[l], charcycle[k], charcycle[j], charcycle[i], '\0'};
                            if (strcmp(crypt(charlist5, salt), argv[1]) == 0)
                            {
                                printf("%s\n", charlist5);
                                return 0;
                            }
                        }
                        ii++;
                    }
                    jj++;
                }
                kk++;
            }
            ll++;
        }
    }
}