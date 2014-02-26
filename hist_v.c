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
#define MAX_WORD 24

/*  count lines, words, and characters in input */
int main()
{
    int i, j, c, nc, max_cnt;
    int hist[MAX_WORD];
    nc = 0;
    max_cnt = 0;
    for (i = 0; i < MAX_WORD; ++i) {
        hist[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++hist[nc];
            nc = 0;
        } else {
            ++nc;
        }
    }

    for (i = 0; i < MAX_WORD; i++) {
        if (hist[i] > max_cnt) {
            max_cnt = hist[i];
        }
    }

    for (i = max_cnt; i > 0; i--) {
        for (j = 0; j < MAX_WORD; j++) {
            if (hist[j] >= i)
                printf(" ## ");
            else
                printf("----");
        }
        printf("\n");
    }

    for (i = 0; i < MAX_WORD; i++)
        printf(" %2d ", i);
    return 0;
}
