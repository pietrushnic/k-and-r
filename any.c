/*
 * =====================================================================================
 *
 *       Filename:  squeeze2.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/10/2014 11:10:57 PM
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

int getl(char line[], int maxline);
int any(char s[], char c[]);

/*  print the longest input line */
int main()
{
    int len;   /* current line length */

    char line[MAXLINE];     /*  current input line */
    char line2[MAXLINE];     /*  current input line */

    while ((len = getl(line, MAXLINE)) > 0 ) {
        if ((len = getl(line2, MAXLINE)) > 0) {
            printf("line:%s", line);
            printf("line2:%s", line2);
            printf("any:%d\n", any(line, line2));
        }
    }
    return 0;
}

/*  getline: read a line into s, return length */
int getl(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/*  squeeze: delete all c from s */
int any(char s[], char c[])
{
    int i, j, k, found;
    int len_c = 0;
    while (c[len_c] != '\n') {
        len_c++;
    }
    for (i = j = 0; s[i] != '\0'; i++) {
        found = 0;
        for (k = 0; k < len_c; k++) {
            if (s[i] == c[k])
                return i;
        }
        if (!found)
            s[j++] = s[i];
    }
    s[j] = '\0';
    return -1;
}
