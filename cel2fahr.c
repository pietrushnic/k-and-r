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
/*  print Fahrenheit-Celsius table
 *  for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = -50;      /*  lower limit of temperatuire scale */
    upper = 200;    /*  upper limit */
    step = 5;      /*  step size */

    celsius = lower;
    printf("cel    fahr\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
