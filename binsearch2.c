/*
 * =====================================================================================
 *
 *       Filename:  binsearch2.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/12/2014 10:49:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>

int binsearch2(int x, int v[], int n);

int main(int argc, const char *argv[])
{
    int n = 1000000;
    int x = 500001;
    int v[n];
    int k;
    for (k = 0; k < n; k++)
        v[k] = k;
    int i = binsearch2(x, v, n);
    printf("binsearch:v[%d]:%d\n", i, v[i]);
    return 0;
}

/*  binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low+high)/2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low+high)/2;
    }
    if (x == v[mid])
        return mid;
    return -1; /*  no match */
}

