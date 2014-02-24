/*
 * =====================================================================================
 *
 *       Filename:  count.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/24/2014 11:56:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
/*  count characters in input; 1st version */
int main()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
    return 0;
}
