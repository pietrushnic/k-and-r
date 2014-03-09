/*
 * =====================================================================================
 *
 *       Filename:  detab.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/09/2014 09:13:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Piotr Król (pietrushnic), pietrushnic@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLINE 1048575 /*  maximum input line length */
#define TAB_STOP 4

int getl(char line[], int maxline);
void entab(char s[], int len);

/*  print the longest input line */
int main()
{
    int len;   /* current line length */

    char line[MAXLINE];     /*  current input line */

    while ((len = getl(line, MAXLINE)) > 0) {
        printf("%s", line);
        entab(line, len);
    }
    return 0;
}

/*  getline: read a line into s, return length */
int getl(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void entab(char s[], int len)
{
    int i, j, k, space_cnt;
    char temp[MAXLINE];
    for (i = 0, j = 0; i < len; i++) {
        if (s[i] == ' ') {
            space_cnt = 0;
            for (k = 0; k < TAB_STOP; k++) {
                if (s[i+k] == ' ') {
                    space_cnt++;
                }
            }
            if (space_cnt == TAB_STOP) {
                temp[j] = '\t';
                i = i + TAB_STOP - 1;
            } else {
                temp[j] = s[i];
            }
        } else {
            temp[j] = s[i];
        }
        j++;
    }
    printf("%s", temp);
}

