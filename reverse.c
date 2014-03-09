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
void reverse(char line[], int len);

/*  print the longest input line */
int main()
{
    int len;   /* current line length */

    char line[MAXLINE];     /*  current input line */

    while ((len = getl(line, MAXLINE)) > 0) {
        printf("%s", line);
        reverse(line, len);
    }
    return 0;
}

/*  getline: read a line into s, return length */
int getl(char s[],int lim)
{
    int c, i, j, prev;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        prev = 1;
        for (j = i - 1; j > 0; j--) {
            if (((s[j] == '\t') || (s[j] == ' ')) && prev) {
                i = j;
                prev = 1;
            } else {
                prev = 0;
            }
        }
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    if (i == 1)
        s[0] = '\0';
    return i;
}

void reverse(char s[], int len)
{
    char temp[len];
    int i, j = 0;
    for (i = len - 1; i >= 0; i--) {
        if ( s[i] != '\0' && s[i] != '\n') {
            temp[j] = s[i];
            j++;
        }
    }
    temp[j] = '\n';
    temp[j+1] = '\0';
    printf("%s", temp);
}
