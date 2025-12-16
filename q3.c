#include <stdio.h>

struct Person {
    char fullName[30];
    int years;
    int baseScore;
};

struct Report {
    int dayNum;
    int delta;
};

int computeFinal(struct Person *pt, struct Report list[], int count)
{
    if (count == 0)
        return pt->baseScore;

    int previous = computeFinal(pt, list, count - 1);
    int adjustment = list[count - 1].delta;

    return previous + adjustment;
}

int main()
{
    struct Person pat;
    struct Report logs[15];
    int totalDays;

    printf("Enter: Name Age StartingHealth\n");
    scanf("%s %d %d", pat.fullName, &pat.years, &pat.baseScore);

    printf("How many daily entries? ");
    scanf("%d", &totalDays);

    printf("Provide each entry as: day change\n");
    for (int idx = 0; idx < totalDays; idx++) {
        scanf("%d %d", &logs[idx].dayNum, &logs[idx].delta);
    }

    int finalVal = computeFinal(&pat, logs, totalDays);

    printf("After %d days, final health = %d\n", totalDays, finalVal);

    return 0;
}
