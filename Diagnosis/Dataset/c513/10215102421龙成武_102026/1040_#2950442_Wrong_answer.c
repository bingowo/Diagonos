#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ABO[4][4][4] = { 1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,
                   1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,
                    1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,
                     1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1 };
int valofabo(char* x);
void myPrint(int a, int ab, int b, int o);
int main()
{
    int i, j, k, flag, a, b, ab, o;
    char f[3], m[3], c[3];
    scanf("%s %s %s", f, m, c);
    flag = 0; //默认是impossible
    a = b = ab = o = 0;
    if (strcmp(f, "?") == 0)
    {
        j = valofabo(m);
        k = valofabo(c);
        for (i = 0;i < 4;i++)
        {
            if (ABO[i][j][k] == 1)
            {
                flag = 1;
                if (i == 0)        a++;
                else if (i == 1)   ab++;
                else if (i == 2)   b++;
                else            o++;
            }
        }
    }
    else if (strcmp(m, "?") == 0)
    {
        i = valofabo(f);
        k = valofabo(c);
        for (j = 0;j < 4;j++)
        {
            if (ABO[i][j][k] == 1)
            {
                flag = 1;
                if (j == 0)        a++;
                else if (j == 1)   ab++;
                else if (j == 2)   b++;
                else            o++;
            }
        }
    }
    else
    {
        i = valofabo(f);
        j = valofabo(m);
        for (k = 0;k < 4;k++)
        {
            if (ABO[i][j][k] == 1)
            {
                flag = 1;
                if (k == 0)        a++;
                else if (k == 1)   ab++;
                else if (k == 2)   b++;
                else            o++;
            }
        }
    }

    if (strcmp(f, "?") == 0)
    {
        if (flag == 1)
            myPrint(a, ab, b, o);
        else
            printf("impossible");
        printf(" %s %s", m, c);
    }
    else if (strcmp(m, "?") == 0)
    {
        printf("%s ", f);
        if (flag == 1)
            myPrint(a, ab, b, o);
        else
            printf("impossible ");
        printf("%s", c);
    }
    else if (strcmp(c, "?") == 0)
    {
        printf("%s %s", f, m);
        myPrint(a, ab, b, o);
    }

    return 0;
}
int valofabo(char* x)
{
    int val = 0;
    if (strcmp(x, "A") == 0)
        val = 0;
    else if (strcmp(x, "AB") == 0)
        val = 1;
    else if (strcmp(x, "B") == 0)
        val = 2;
    else
        val = 3;
    return val;
}
void myPrint(int a, int ab, int b, int o)
{
    int numofd = -1;
    if (a != 0)        numofd++;
    if (ab != 0)  numofd++;
    if (b != 0)   numofd++;
    if (o != 0)   numofd++;
    printf("{");
    if (a != 0)
    {
        printf("A");
        if (numofd > 0)
        {
            printf(",");numofd--;
        }
    }
    if (ab != 0)
    {
        printf("AB");
        if (numofd > 0)
        {
            printf(",");numofd--;
        }

    }
    if (b != 0)
    {
        printf("B");
        if (numofd > 0)
        {
            printf(",");numofd--;
        }
    }
    if (o != 0)
    {
        printf("O");
        if (numofd > 0)
        {
            printf(",");numofd--;
        }
    }
    printf("}");
}
