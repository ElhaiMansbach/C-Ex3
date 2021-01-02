#include <stdio.h>
#include <string.h>
#include "txtfind.h"

int getLine(char s[])
{
    int i, j, c;
    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i < LINE - 1)
        {
            s[j++] = c;
        }
    }
    if (c == '\n')
    {
        if (i <= LINE - 1)
        {
            s[j++] = c;
        }
        i++;
    }
    s[j] = '\0';
    return i;
}

int getword(char w[])
{
    char c = getchar();
    int i, j;
    if (c == '\n' || c == ' ' || c == '\t')
    {
        w[0] = '\0';
        return 1;
    }
    for (i = 0, j = 0; c != EOF && c != '\n' && c != '\t' && c != ' '; i++)
    {
        if (i < LINE - 1)
        {
            w[j++] = c;
            c = getchar();
        }
    }
    w[j] = '\0';
    return i;
}

int substring(char *str1, char *str2)
{
    char *cp = str1;
    char *s1, *s2;
    if (!*str2)
        return 1;
    while (*cp)
    {
        s1 = cp;
        s2 = str2;
        while (*s1 && *s2 && !(*s1 - *s2))
            s1++, s2++;
        if (!*s2)
            return 1;
        cp++;
    }
    return 0;
}

int similar(char *s, char *t, int n)
{
    int i = 0;
    while (i <= n && *s != '\0')
    {
        if (*s == *t)
        {
            s++;
            t++;
        }
        else
        {
            s++;
            i++;
        }
    }
    if (i <= n && *s == '\0' && *t == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_lines(char *str)
{
    char line[LINE];
    while (getLine(line))
    {
        if (substring(line, str))
        {
            puts(line);
        }
    }
}

void print_similar_words(char *str)
{
    char word[WORD];
    while (getword(word))
    {
        if (similar(word, str, 1))
        {
            puts(word);
        }
    }
}