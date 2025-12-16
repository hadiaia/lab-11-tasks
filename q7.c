#include <stdio.h>

int bestTip(int arr[], int total, int index)
{
    if (index >= total)
        return 0;

    int option1 = arr[index] + bestTip(arr, total, index + 2);
    int option2 = bestTip(arr, total, index + 1);

    int result = (option1 > option2) ? option1 : option2;
    return result;
}

int main()
{
    int stops;

    printf("How many stops are there? ");
    scanf("%d", &stops);

    int amounts[stops];
    printf("Enter the tips for each stop:\n");

    for (int j = 0; j < stops; j++)
        scanf("%d", &amounts[j]);

    int maxCollected = bestTip(amounts, stops, 0);

    printf("Maximum achievable tip: %d\n", maxCollected);

    return 0;
}
