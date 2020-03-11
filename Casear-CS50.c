#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char encrypto(char string[], int a);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    else
    {
        string plaintext = get_string("Enter your message: ");
        printf("plaintext: %s\n", plaintext);
        printf("ciphertext: ");
        int key = atoi(argv[1]);

        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    char uppercharacter = plaintext[i];
                    uppercharacter = (((uppercharacter - 65)+ key) % 26) + 65;
                    printf("%c", uppercharacter);
                }
                else
                {
                    char lowercharacter = plaintext[i];
                    lowercharacter = (((lowercharacter - 97) + key) % 26) + 97;
                    printf("%c", lowercharacter);
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
}