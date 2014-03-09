/*
 * =====================================================================================
 *
 *       Filename:  ranges.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/09/2014 11:14:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(int argc, const char *argv[])
{
    short s = 0;
    int i = 0;
    char c = 0;
    unsigned long ul = 0;
    signed long sl = 0;
    long long max;

    printf("short:%ld bytes\n", sizeof(s));
    printf("int:%ld bytes\n", sizeof(i));
    printf("char:%ld bytes\n", sizeof(c));
    printf("unsigned long:%ld bytes\n", sizeof(ul));
    printf("signed long:%ld bytes\n", sizeof(sl));

    max = 0;
    while(1) {
        s++;
        if (s > max) {
            max = s;
        } else {
            break;
        }
    }
    printf("max: %lld\n", max);
    printf("short max: %d\n", s);
    max = 0;
    while(1) {
        i++;
        if (i > max) {
            max = i;
        } else {
            break;
        }
    }
    printf("max: %lld\n", max);
    printf("int max: %d\n", i);
    max = 0;
    while(1) {
        c++;
        if (c > max) {
            max = c;
        } else {
            break;
        }
    }
    printf("max: %lld\n", max);
    printf("char:%d\n", c);
    max = 0;
    ul = 0x7FFFFFFFFFFFFFFF;
    while(1) {
        ul--;
        if (ul < max) {
            printf("%ld\n", ul);
            max = ul;
        } else {
            break;
        }
    }
    printf("max: %lld\n", max);
    printf("unsigned long:%ld\n", ul);
    printf("signed long:%ld bytes\n", sizeof(sl));
    return 0;
}
