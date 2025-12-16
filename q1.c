#include <stdio.h>
#include <math.h>

struct Building {
    int buildingID;
    int startHeight;
    float rate;
};

int computeHeight(struct Building *b, int days)
{
    int h = b->startHeight;

    for (int d = 0; d < days; d++) {
        int growth = (int)(h * b->rate);
        h = h + growth;
    }

    return h;
}

int main()
{
    struct Building myBuilding = {1, 100, 0.10f};
    int inputDay;

    printf("Enter number of days: ");
    scanf("%d", &inputDay);

    int finalHeight = computeHeight(&myBuilding, inputDay);

    printf("Predicted Height: %d\n", finalHeight);
    return 0;
}
