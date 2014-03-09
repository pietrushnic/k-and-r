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
#define MAX_WORD 96

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
        if (c > 31 && c < 128)
        ++hist[c-32];
    }

    for (i = 0; i < MAX_WORD; i++) {
        if (hist[i] > max_cnt) {
            max_cnt = hist[i];
        }
    }

    for (i = max_cnt; i > 0; i--) {
        for (j = 0; j < MAX_WORD; j++) {
            if (hist[j] >= i)
                printf("#");
            else
                printf("-");
        }
        printf("\n");
    }

    for (i = 32; i < MAX_WORD + 32; i++)
        printf("%c", i);
    return 0;
}
