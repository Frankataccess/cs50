#include <stdio.h>
#include <cs50.h>

// Function to iterate blocks
void blanks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

// Function to print blocks
void blocks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

int main(void)
{
    // Get height of the pyramid
    int height;

    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }

    while (height < 1 || height > 8);

    // Print the pyramid
    for (int i = 0; i < height; i++)
    {
        // print blanks
        blanks(height - i - 1);

        // Print left blocks
        blocks(i + 1);

        // Print gap
        printf("  ");

        // Print right blocks
        blocks(i + 1);

        // Move to the next line
        printf("\n");
    }

    return 0;
}
