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
void detab(char s[], int len);

/*  print the longest input line */
int main()
{
    int len;   /* current line length */

    char line[MAXLINE];     /*  current input line */

    while ((len = getl(line, MAXLINE)) > 0) {
        printf("%s", line);
        detab(line, len);
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

void detab(char s[], int len)
{
    int i, j, k;
    char temp[MAXLINE];
    for (i = 0, j = 0; i < len; i++) {
        if (s[i] == '\t') {
            for (k = 0; k < TAB_STOP; k++) {
                temp[j+k] = ' ';
            }
            j += TAB_STOP;
        } else {
            temp[j] = s[i];
            j++;
        }
    }
    printf("%s", temp);
}

