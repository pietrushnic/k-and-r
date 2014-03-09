/*
 * =====================================================================================
 *
 *       Filename:  for.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/10/2014 12:16:22 AM
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
    int i;
    char c;
    int lim = 10;
    for(i=0; i < lim-1 ? ((c=getchar()) != '\n' ? (c != EOF ? 1 : 0) : 0) : 0; i++) {
        printf("i:%d c:%c\n",i,c);
    }
    return 0;
}
