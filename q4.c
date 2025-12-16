#include <stdio.h>

struct Weather {
    char place[20];
    double startTemp;
    double factor;
};

double computeTemp(double temp, double k, int days)
{
    if (days == 0)
        return temp;

    double oldVal = computeTemp(temp, k, days - 1);
    double next = oldVal - k + 1;

    return next;
}

int main()
{
    struct Weather W;
    
    printf("Enter City, Initial Temperature, Cooling Value:\n");
    scanf("%s %lf %lf", W.place, &W.startTemp, &W.factor);

    double result = computeTemp(W.startTemp, W.factor, 5);

    printf("Computed temperature after 5 days: %.3lf\n", result);

    return 0;
}
