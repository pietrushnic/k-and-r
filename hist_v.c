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
    int i, j, c, nc, state, max_cnt, max_cnt_pos, included, zero_cnt, index, cur_pos;
    int hist[MAX_WORD], sort[MAX_WORD], sort_pos[MAX_WORD];
    nc = 0;
    zero_cnt = 0;
    index = 0;
    max_cnt = 0;
    for (i = 0; i < MAX_WORD; ++i) {
        hist[i] = 0;
        sort[i] = 0;
        sort_pos[i] = 0;
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
        if (hist[i] == 0) zero_cnt++;
        if (hist[i] > max_cnt) {
            max_cnt = hist[i];
        }
    }

    for (i = max_cnt; i > 0; i--) {
        for (j = 0; j < MAX_WORD; j++) {
            if (hist[j] == i) {
                sort[index] = i;
                sort_pos[index] = j;
                index++;
            }
        }
    }

    printf("index:%d\n",index);
    for (j = index; j >= 0; j--) {
        printf("sort[%d]:%d\n",j,sort[j]);
        printf("sort_pos[%d]:%d\n",j,sort_pos[j]);
    }

    for (i = max_cnt; i > 0; i--) {
        cur_pos = 0;
        for (j = 0; j < MAX_WORD; j++) {
            if (sort[j] >= i) {
                if(cur_pos < sort_pos[j]) {
                    printf("%2d-%d", sort_pos[j], cur_pos);
                    cur_pos++;
                }
                printf("%2dX%d", sort_pos[j], cur_pos);
                cur_pos++;
            }
        }
        printf("\n");
    }

    for (i = 0; i < MAX_WORD; i++)
        printf(" %2d ", i);
}
