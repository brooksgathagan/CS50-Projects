#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    string keytext = argv[1];
    
    if (argc == 2)
    {
        for (int i = 0; i < strlen(keytext); i++)
        {
            if (isalpha(keytext[i]) == false)
            {
                printf("Usage: ./caesar k\n");
                return 1;
            }
        }
    }

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

        for (int i = 0, keyindex = 0; i < strlen(plaintext); i++)
        {
            if (isalpha(plaintext[i]))
            {

                if (keyindex == strlen(keytext))
                {
                    keyindex = 0;
                }

                if (isupper(plaintext[i]) && isupper(keytext[keyindex]))
                {
                    int key1 = keytext[keyindex] - 65;
                    char character1 = (((plaintext[i] - 65) + key1) % 26) + 65;
                    printf("%c", character1);
                }
                else if (isupper(plaintext[i]) && islower(keytext[keyindex]))
                {
                    int key2 = keytext[keyindex] - 97;
                    char character2 = (((plaintext[i] - 65) + key2) % 26) + 65;
                    printf("%c", character2);
                }
                else if (islower(plaintext[i]) && isupper(keytext[keyindex]))
                {
                    int key3 = keytext[keyindex] - 65;
                    char character3 = (((plaintext[i] - 97) + key3) % 26) + 97;
                    printf("%c", character3);
                }
                else
                {
                    int key4 = keytext[keyindex] - 97;
                    char character4 = (((plaintext[i] - 97) + key4) % 26) + 97;
                    printf("%c", character4);
                }
                keyindex++;
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
