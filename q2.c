#include <stdio.h>

struct Loan {
    char borrower[20];
    double principal;
    double interest;
    double duration;
    double perMonth;
};

double calculate(struct Loan *ln, int step)
{
    if (step == 0)
        return ln->principal;

    double prev = calculate(ln, step - 1);

    double reduce = prev - ln->perMonth;
    double addInterest = reduce * ln->interest;

    return reduce + addInterest;
}

int main()
{
    struct Loan L;

    printf("Enter Loan Info: Name, Principal, Rate, Months, Monthly Payment:\n");
    scanf("%s %lf %lf %lf %lf",
          L.borrower, &L.principal, &L.interest, &L.duration, &L.perMonth);

    int totalSteps = (int) L.duration;

    printf("Remaining Balance: %.1lf\n", calculate(&L, totalSteps));

    return 0;
}
