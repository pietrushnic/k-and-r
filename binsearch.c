/*
 * =====================================================================================
 *
 *       Filename:  binsearch.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/12/2014 10:48:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, const char *argv[])
{
    int n = 1000000;
    int x = 500001;
    int v[n];
    int k;
    for (k = 0; k < n; k++)
        v[k] = k;
    int i = binsearch(x, v, n);
    printf("binsearch:v[%d]:%d\n", i, v[i]);
    return 0;
}

/*  binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid; /*  found match */
    }
    return -1; /*  no match */
}
