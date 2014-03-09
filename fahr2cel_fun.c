/*
 * =====================================================================================
 *
 *       Filename:  cel2fahr.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/24/2014 11:19:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
float fahr2cel(float fahr);
/*  print Fahrenheit-Celsius table
 *  for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;      /*  lower limit of temperatuire scale */
    upper = 300;    /*  upper limit */
    step = 20;      /*  step size */

    fahr = upper;
    printf("fahr   cel\n");
    while (fahr >= lower) {
        printf("%3.0f %6.1f\n", fahr, fahr2cel(fahr));
        fahr = fahr - step;
    }
    return 0;
}

float fahr2cel(float fahr) {
        return (5.0/9.0) * (fahr-32.0);
}
