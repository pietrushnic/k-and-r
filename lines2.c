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
    int c, s;
    s = 0;
    while ((c = getchar()) != EOF) {
        if(c == ' ' && !s) {
            s = 1;
            printf("%c", c);
        }

        if (c != ' ') {
            s = 0;
            printf("%c", c);
        }
    }
    return 0;
}
