/*
 * =====================================================================================
 *
 *       Filename:  char.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/24/2014 11:44:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
/*  copy input to output; 1st version */
int main()
{
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
    return 0;
}
