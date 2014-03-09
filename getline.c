/*
 * =====================================================================================
 *
 *       Filename:  getline.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/26/2014 09:48:29 PM
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
void copy(char to[], char from[]);

/*  print the longest input line */
int main()
{
    int len;   /* current line length */
    int max;   /* maximum length seen so far */

    char line[MAXLINE];     /*  current input line */
    char longest[MAXLINE];  /*  longest line saved here */

    max = 0;
    while ((len = getl(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /*  there was a line */
        printf("%s", longest);
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

/*  copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
