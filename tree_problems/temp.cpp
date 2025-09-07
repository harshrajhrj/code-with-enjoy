#include <stdio.h>
#include <math.h>

// helper function to calculate factorial
long double factorial(int n)
{
    long double fact = 1.0;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    int n_terms;
    double x_degrees;
    double sum = 0.0;

    printf("Enter the value of X in degrees: ");
    scanf("%lf", &x_degrees);
    printf("Enter the number of terms in the series: ");
    scanf("%d", &n_terms);

    // convert degrees to radians
    double x_radians = x_degrees * (3.14159265359 / 180.0);
    printf("Converted radian: %lf\n", x_radians);

    // calculate sum of the series
    for (int i = 0; i < n_terms; i++)
    {
        double sign = pow(-1, i);
        double power = pow(x_radians, 2 * i);
        double fact = factorial(2 * i);

        sum += (sign * power) / fact;
    }

    printf("Sum of the series = %lf\n", sum);
    printf("Value of cos(%.2lf) using library function = %lf\n", x_degrees, cos(x_radians));

    return 0;
}
