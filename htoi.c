/*
 * =====================================================================================
 *
 *       Filename:  htoi.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/10/2014 10:12:21 PM
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
int htoi(char line[], int len);

int main(int argc, const char *argv[])
{
    int len;   /* current line length */
    char line[MAXLINE];     /*  current input line */
    while ((len = getl(line, MAXLINE)) > 0)
        printf("htoi:%d\n", htoi(line, len));
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

int htoi(char s[], int len) {
    int j, k, base, count, sum = 0, i = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i += 2;
        len -= 2;
    }

    for (j = 0; j < len; j++, i++) {
        base = 1;
        for (k = 0; k < j; k++) {
            base *= 16;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            count = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            count = s[i] - 87;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            count = s[i] - 55;
        } else if (s[i] == '\n') {
            continue;
        }
        sum += (count * base);
    }
    return sum;
}
