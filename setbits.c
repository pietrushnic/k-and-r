/*
 * =====================================================================================
 *
 *       Filename:  setbits.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/10/2014 11:51:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightmost(unsigned x, int n);
unsigned rightrot(unsigned x, int n);

int main(int argc, const char *argv[])
{
    int x, p, n, y;
    x = 0xEE;
    p = 4;
    n = 1;
    y = 0x3;

    printf("x:%x\n", getbits(x,p,n));
    printf("x:%x\n", setbits(x,p,n,y));
    printf("x:%x\n", rightmost(x,n));
    printf("x:%x\n", invert(x,p,n));
    printf("x:%x\n", rightrot(x,n));
    return 0;
}

/*  getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned rightmost(unsigned x, int n)
{
    int mask = 0, i = 0;
    for (i = 0; i < n; i++) {
        mask = mask | (1 << i);
    }
    return x & mask;
}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x | rightmost(y,n) << (p - 1);
}

unsigned invert(unsigned x, int p, int n)
{
    int i, mask = 0;
    for (i = 0; i < n; i++) {
        mask = mask | (1 << i);
    }
    mask = mask << (p - 1);
    return x & ~(x & mask);
}

unsigned rightrot(unsigned x, int n)
{

    int i = 0;
    while ((x >> i) > 0)
        i++;
    return rightmost((x << n) | (x >> (i-n)), i);
}
