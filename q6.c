#include <stdio.h>

struct Info {
    char studentName[20];
    int yearsOld;
};

struct Learner {
    struct Info details;
    int hours[5];
    int feeRate;
};

int computeFee(struct Learner *L, int count)
{
    if (count == 0)
        return 0;

    int prev = computeFee(L, count - 1);
    int curr = L->hours[count - 1] * L->feeRate;

    return prev + curr;
}

int main()
{
    struct Learner stu;
    
    printf("Enter: Name Age RatePerCredit\n");
    scanf("%s %d %d", stu.details.studentName, &stu.details.yearsOld, &stu.feeRate);

    printf("Enter 5 credit-hour entries:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &stu.hours[i]);
    }

    int total = computeFee(&stu, 5);

    printf("Total Fee = %d\n", total);

    return 0;
}
