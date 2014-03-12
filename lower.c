/*
 * =====================================================================================
 *
 *       Filename:  lower.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/12/2014 10:33:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>

int lower(int c);
int lower2(int c);

int main(int argc, const char *argv[])
{
    char c = 'A';
    printf("condition:%c\n", (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c);
    printf("lower:%c\n", lower(c));
    return 0;
}

/*  lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
