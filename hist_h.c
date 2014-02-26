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
#define MAX_WORD 24

/*  count lines, words, and characters in input */
int main()
{
    int i, j, c, nc, state;
    int hist[MAX_WORD];
    state = OUT;
    nc = 0;
    for (i = 0; i < MAX_WORD; ++i)
        hist[i] = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++hist[nc];
            nc = 0;
        } else {
            ++nc;
        }
    }
    for (i = 0; i < MAX_WORD; ++i) {
        printf("%2d:", i);
        for (j = 0; j < hist[i]; j++ ) {
            printf("#");
        }
        printf("\n");
    }
}
