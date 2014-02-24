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
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\\') {
            printf("\\\\");
            continue;
        }
        if (c == '\t') {
            printf("\\t");
            continue;
        }
        if (c == '\b') {
            printf("\\b");
            continue;
        }
        printf("%c", c);
    }
    return 0;
}
