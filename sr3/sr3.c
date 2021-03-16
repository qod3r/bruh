#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double Recursive(double arg, double eps, double temp, double sum, int i) {
    if (fabs(temp) >= eps) {
        i += 2;
        temp *= -(arg * arg) / (i * (i - 1));
        sum += temp;
        return Recursive(arg, eps, temp, sum, i);
    } else {
        return sum;
    }
}

double NonRecursive(double arg, double eps) {
    double sum = 1, temp = 1;
    int i = 0;
    while (fabs(temp) >= eps) {
        i += 2;
        temp *= -(arg * arg) / (i * (i - 1));
        sum += temp;
    }
    return sum;
}

int main() {
    double arg, eps;
    printf("Введите аргумент cos(в градусах) и точность ε: ");
    scanf("%lf %lf", &arg, &eps);

    // перевод в радианы
    arg = arg * M_PI / 180;

    printf("%.15lf\n", NonRecursive(arg, eps));
    printf("%.15lf\n", Recursive(arg, eps, 1, 1, 0));
}