/*
 * =====================================================================================
 *
 *       Filename:  escape.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/12/2014 11:33:11 PM
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
void escape (char s[], char t[]);
void deescape (char s[], char t[]);

/*  print the longest input line */
int main()
{
    int len;   /* current line length */

    char line[MAXLINE];     /*  current input line */
    char out[MAXLINE];     /*  current input line */
    char out2[MAXLINE];     /*  current input line */

    while ((len = getl(line, MAXLINE)) > 0) {
        escape(out, line);
        printf("out:%s", out);
    }
    deescape(out2, out);
    printf("out2:%s", out2);

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

void escape (char s[], char t[])
{
    int i, j, count = 0;
    while(t[count] != '\0')
        count++;
    for (i = 0, j = 0; i < count; i++) {
        switch (t[i]) {
            case 32:
                s[j] = '\\';
                s[j+1] = 's';
                j++;
                break;
            case 9:
                s[j] = '\\';
                s[j+1] = 't';
                j++;
                break;
            default:
                s[j] = t[i];
        }
        j++;
    }
}

void deescape (char s[], char t[])
{
    int i, j, count = 0;
    while(t[count] != '\0')
        count++;
    for (i = 0, j = 0; i < count; i++) {
        switch (t[i]) {
            case 92:
                switch(t[i+1]) {
                    case 115:
                        s[j] = 32;
                        i++;
                        break;
                    case 116:
                        s[j] = 9;
                        i++;
                        break;
                    default:
                        s[j] = t[i];
                }
                break;
            default:
                s[j] = t[i];
        }
        j++;
    }
}
