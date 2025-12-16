#include <stdio.h>
#include <math.h>

struct FileData {
    char title[30];
    double sizeStart;
    double shrinkRate;
};

double computeCompress(struct FileData *f, int step)
{
    if (step == 0)
        return f->sizeStart;

    double previous = computeCompress(f, step - 1);

    double amount = ceil(previous * (f->shrinkRate));

    double newSize = previous - amount;

    return newSize;
}

int main()
{
    struct FileData info;
    int rounds;

    printf("Input: name, initial size, reduction percentage:\n");
    scanf("%s %lf %lf", info.title, &info.sizeStart, &info.shrinkRate);

    printf("How many compression cycles? ");
    scanf("%d", &rounds);

    double outcome = computeCompress(&info, rounds);

    printf("File size after %d cycles: %.2lf\n", rounds, outcome);

    return 0;
}
