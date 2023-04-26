#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000

void duplicate(char *s, int pos) 
{
    for (int i = strlen(s) + 1; i > pos; i--)
        s[i] = s[i - 1];
}

int main()
{
    char s[MAXLEN];
    scanf("%s", s);
    char t[10 * MAXLEN];
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        duplicate(strcpy(t, s), i);
        if (strcmp(t, s) < 0)
            len++, i++, strcpy(s, t);
    }
    printf("%s\n", s);
    return 0;
}
