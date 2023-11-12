#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start_size;
    printf("Enter the start population of llamas: ");
    scanf("%d", &start_size);

    // Check if the start size is less than 9
    if (start_size < 9)
    {
        printf("The population of llamas will become stagnant very quickly. Please get more llamas.\n");
        return 1; // Exit the program with an error code
    }

    // Prompt for end size
    int end_size;
    printf("Enter the end population of llamas: ");
    scanf("%d", &end_size);

    // Check if the end size is less than the start size
    if (end_size < start_size)
    {
        printf("The end population should be greater than or equal to the start population.\n");
        return 1; // Exit the program with an error code
    }

    // Calculate number of years until we reach the threshold
    int years = 0;
    while (start_size < end_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }

    // Print number of years
    printf("It will take %d years for the population to reach %d llamas.\n", years, end_size);

    return 0; // Exit the program successfully
}