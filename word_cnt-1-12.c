/*
 * =====================================================================================
 *
 *       Filename:  word_cnt.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/25/2014 08:58:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#define IN  1   /*  inside a word */
#define OUT 0   /*  outside a word */

/*  count lines, words, and characters in input */
int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            printf("\n");
        else
            printf("%c", c);
    }
}
