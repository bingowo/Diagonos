#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101

int duplicate(char *a)
{
    int len = strlen(a);
    char *b = (char *)malloc(sizeof(char) * N * 10000000);
    if (a[0] != a[1])
    {
        char c[2];
        sprintf(c, "%c", a[0]);
        strcat(b, c);
    }
    for (int i = 1; i < len - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            if (a[i] != a[i - 1])
            {
                char c[2];
                sprintf(c, "%c", a[i]);
                strcat(b, c);
            }
        }
    }
    if (a[len - 2] != a[len - 1])
    {
        char c[2];
        sprintf(c, "%c", a[len - 1]);
        strcat(b, c);
    }

    len = strlen(b);
    int jud = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (b[i] == b[i + 1])
        {
            jud = 1;
            break;
        }
    }
    if (jud)
        return duplicate(b);
    else
        return strlen(b);
}

void insert(char *s, int pos, int flag)
{
    int len = strlen(s);
    for (int i = len + 1; i > pos; i--)
        s[i] = s[i - 1];
    if (flag == 1)
        s[pos] = 'A';
    else if (flag == 2)
        s[pos] = 'B';
    else
        s[pos] = 'C';
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        char a[N];
        scanf("%s", a);
        int len = strlen(a);
        int removal = 0;
        for (int j = 0; j < len; j++)
        {
            char a1[N];
            strcpy(a1, a);
            insert(a1, j, 1);
            int b1 = duplicate(a1);
            int disa = strlen(a1) - b1;
            if (disa > removal)
                removal = disa;

            char a2[N];
            strcpy(a2, a);
            insert(a2, j, 2);
            int b2 = duplicate(a2);
            disa = strlen(a2) - b2;
            if (disa > removal)
                removal = disa;

            char a3[N];
            strcpy(a3, a);
            insert(a3, j, 3);
            int b3 = duplicate(a3);
            disa = strlen(a3) - b3;
            if (disa > removal)
                removal = disa;
        }
        printf("case #%d:\n%d\n", i, removal);
    }
    return 0;
}