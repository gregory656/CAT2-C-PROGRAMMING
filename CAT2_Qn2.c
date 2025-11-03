#include <stdio.h>

int main() {
    double hours, rate;
    double grossPay, tax, netPay;

    // Input
    printf("Enter hours worked in a week: ");
    scanf("%lf", &hours);
    printf("Enter hourly wage: ");
    scanf("%lf", &rate);

    // Calculate gross pay
    if (hours > 40)
        grossPay = (40 * rate) + ((hours - 40) * rate * 1.5);
    else
        grossPay = hours * rate;

    // Calculate taxes
    if (grossPay <= 600)
        tax = grossPay * 0.15;
    else
        tax = (600 * 0.15) + ((grossPay - 600) * 0.20);

    // Net pay
    netPay = grossPay - tax;

    // Output results
    printf("\nGross Pay: $%.2f", grossPay);
    printf("\nTaxes: $%.2f", tax);
    printf("\nNet Pay: $%.2f\n", netPay);

    return 0;
}