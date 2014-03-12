/*
 * =====================================================================================
 *
 *       Filename:  bitcount.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/12/2014 10:16:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>

int bitcount(unsigned x);
int bitcount2(unsigned x);
int main(int argc, const char *argv[])
{

    printf("bitcount:%d\n", bitcount(0xF));
    printf("bitcount2:%d\n", bitcount2(0xF));
    return 0;
}

/*  bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}


int bitcount2(unsigned x)
{
    int b;
    for (b = 0, x &= (x-1) ; x != 0; x >>= 1)
        b++;
    return b;
}
