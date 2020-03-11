#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    long long ccnumber;

    // Ask user for CC number

    do
    {
        ccnumber = get_long_long("Enter Credit Card Number: ");
    }
    while (ccnumber < 0);

    int ccdigits = 0;
    long long validation = ccnumber;

    // Figure out how many digits in CC number

    while (validation > 0)
    {
        validation = validation / 10;
        ccdigits++;
    }

    // Isolate every other digit (starting w/ second to last) and multiply by 2

    int digit1 = ((ccnumber / 10) % 10) * 2;
    int digit2 = ((ccnumber / 1000) % 10) * 2;
    int digit3 = ((ccnumber / 100000) % 10) * 2;
    int digit4 = ((ccnumber / 10000000) % 10) * 2;
    int digit5 = ((ccnumber / 1000000000) % 10) * 2;
    int digit6 = ((ccnumber / 100000000000) % 10) * 2;
    int digit7 = ((ccnumber / 10000000000000) % 10) * 2;
    int digit8 = ((ccnumber / 1000000000000000) % 10) * 2;

    // Add the digits from the products above

    int sum1 = (digit1 % 10) + (digit1 / 10);
    sum1 = sum1 + (digit2 % 10) + (digit2 / 10);
    sum1 = sum1 + (digit3 % 10) + (digit3 / 10);
    sum1 = sum1 + (digit4 % 10) + (digit4 / 10);
    sum1 = sum1 + (digit5 % 10) + (digit5 / 10);
    sum1 = sum1 + (digit6 % 10) + (digit6 / 10);
    sum1 = sum1 + (digit7 % 10) + (digit7 / 10);
    sum1 = sum1 + (digit8 % 10) + (digit8 / 10);

    // Isolate every other digit, starting with last

    int digit9 = ccnumber % 10;
    int digit10 = (ccnumber / 100) % 10;
    int digit11 = (ccnumber / 10000) % 10;
    int digit12 = (ccnumber / 1000000) % 10;
    int digit13 = (ccnumber / 100000000) % 10;
    int digit14 = (ccnumber / 10000000000) % 10;
    int digit15 = (ccnumber / 1000000000000) % 10;
    int digit16 = (ccnumber / 100000000000000) % 10;

    // Add these digits

    int sum2 = digit9 + digit10 + digit11 + digit12 + digit13 + digit14 + digit15 + digit16;

    // Add sum & seek remainder (we need 0)

    int sumcheck = (sum1 + sum2) % 10;


    // Testing CC validity

    int mc;
    int visa;
    int aex;

    if (sumcheck == 0)
    {
        if (ccdigits == 16)
        {
            mc = ccnumber / 100000000000000;
            visa = ccnumber / 1000000000000000;
            if (mc > 50 && mc < 56)
            {
                printf("MASTERCARD\n");
            }
            else if (visa == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (ccdigits == 13)
        {
            visa = ccnumber / 1000000000000;
            if (visa == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (ccdigits == 15)
        {
            aex = ccnumber / 10000000000000; // These have been used to identify the first 1-2 numbers, as required per CC.  Here, we're isolating the first two digits.
            if (aex == 34 || aex == 37) // On this line, we're verifying if the first two digits we isolated are 34 or 37
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}.c