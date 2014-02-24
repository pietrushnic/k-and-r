/*
 * =====================================================================================
 *
 *       Filename:  lines.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/25/2014 12:04:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
/*  count lines in input */
int main()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
    return 0;
}
