#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 16

bool luhn_algorithm(char cc_string[], int length);

int main(void)
{
    char cc_string[MAX_LENGTH + 1]; // +1 for null terminator

    // Get number (check input is between 13 and 16 characters long and remove hyphens)
    printf("Number: ");
    scanf("%s", cc_string);

    // Validate the length
    int length = strlen(cc_string);
    if (length < 13 || length > MAX_LENGTH)
    {
        printf("Invalid input length. Please enter a valid credit card number.\n");
        return 1; // Return an error code
    }

    // Remove hyphens from the credit card number
    int index = 0;

    for (int i = 0; i < length; i++)
    {
        if (cc_string[i] != '-')
        {
            cc_string[index] = cc_string[i];
            index++;
        }
    }

    // Null-terminate the sanitized string
    cc_string[index] = '\0';

    // Check if the credit card number is valid using Luhn's algorithm
    if (luhn_algorithm(cc_string, length))
    {
        // Print "Card is valid"
        printf("Card is valid\n");

        // Extract the first two digits for card type checking
        int one_num = cc_string[0] - '0';
        int two_num = cc_string[1] - '0';

        // Card type
        if (one_num == 4)
        {
            printf("Visa\n");
        }
        else if (one_num == 3 && (two_num == 4 || two_num == 7))
        {
            printf("American Express\n");
        }
        else if (one_num == 5 && (two_num >= 1 && two_num <= 5))
        {
            printf("MasterCard\n");
        }
        else
        {
            printf("Invalid card type \n");
        }
    }
    else
    {
        printf("Invalid credit card number.\n");
    }

    // End
    return 0;
}

bool luhn_algorithm(char cc_string[], int length)
{
    int sum = 0;

    // Iterate through each digit of the number from right to left
    for (int i = length - 1; i >= 0; i--)
    {
        int digit = cc_string[i] - '0';

        // For every second digit, double it and add its digits (if the result is two digits)
        if ((length - i) % 2 == 0)
        {
            digit *= 2;
            sum += (digit % 10) + (digit / 10);
        }
        else
        {
            // For every other digit, just add it to the sum
            sum += digit;
        }
    }

    // If the sum modulo 10 is 0, the credit card number is valid
    return sum % 10 == 0;
}