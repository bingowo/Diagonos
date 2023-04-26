#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100

int main()
{
    long sum;
    int T, i, j, t, temp, n[10] = { 0 }, L[10] = { 0 }, co[10][62] = { 0 }, mea[10][62] = { 0 };
    char c, s[10][M] = { 0 };                                
    scanf("%d", &T);
    c = getchar();
    for (i = 0; i < T; i++)
    {
        j = 0;
        while ((c = getchar()) != '\n')
        {
            s[i][j] = c;
            if (('0' <= c) && (c <= '9'))
            {
                temp = c - '0';
                co[i][temp]++;
                if (co[i][temp] == 1)
                {
                    n[i]++;
                }
            }
            else if (('A' <= c) && (c <= 'Z'))
            {
                temp = c - 'A' + 10;
                co[i][temp]++;
                if (co[i][temp] == 1)
                {
                    n[i]++;
                }
            }
            else
            {
                temp = c - 'a' + 36;
                co[i][temp]++;
                if (co[i][temp] == 1)
                {
                    n[i]++;
                }
            }
            j++;
        }
        L[i] = j;
    }
    for (i = 0; i < T; i++)
    {
        
        t = 2;
        for (j = 0; j < L[i]; j++)
        {
            c = s[i][j];
            if (n[i] == 1)
            {
                
                if (('0' <= c) && (c <= '9'))
                {
                    temp = c - '0';
                    mea[i][temp] = 1;
                }
                else if (('A' <= c) && (c <= 'Z'))
                {
                    temp = c - 'A' + 10;
                    mea[i][temp] = 1;
                }
                else
                {
                    temp = c - 'a' + 36;
                    mea[i][temp] = 1;
                }
                break;
            }
            else
            {


                if (j == 0)
                {
                    if (('0' <= c) && (c <= '9'))
                    {
                        temp = c - '0';
                        mea[i][temp] = 1;
                        co[i][temp] = 0;
                    }
                    else if (('A' <= c) && (c <= 'Z'))
                    {
                        temp = c - 'A' + 10;
                        mea[i][temp] = 1;
                        co[i][temp] = 0;
                    }
                    else if (('a'  <=c)&&(c<='z'))
                    {
                        temp = c - 'a' + 36;
                        mea[i][temp] = 1;
                        co[i][temp] = 0;
                    }
                }
                else if ((j == 1)&&(s[i][1]!=s[i][0]))
                {
                    if (('0' <= c) && (c <= '9'))
                    {
                        temp = c - '0';
                        mea[i][temp] = 0;
                        co[i][temp] = 0;
                    }
                    else if (('A' <= c) && (c <= 'Z'))
                    {
                        temp = c - 'A' + 10;
                        mea[i][temp] = 0;
                        co[i][temp] = 0;
                    }
                    else
                    {
                        temp = c - 'a' + 36;
                        mea[i][temp] = 0;
                        co[i][temp] = 0;
                    }
                }
                else
                {
                    if (('0' <= c) && (c <= '9'))
                    {
                        temp = c - '0';
                        if (co[i][temp] > 0)
                        {
                            mea[i][temp] = t;
                            t++;
                            co[i][temp] = 0;
                        }
                    }
                    else if (('A' <= c) && (c <= 'Z'))
                    {
                        temp = c - 'A' + 10;
                        if (co[i][temp] > 0)
                        {
                            mea[i][temp] = t;
                            t++;
                            co[i][temp] = 0;
                        }
                    }
                    else
                    {
                        temp = c - 'a' + 36;
                        if (co[i][temp] > 0)
                        {
                            mea[i][temp] = t;
                            t++;
                            co[i][temp] = 0;
                        }
                    }
                    if (t == n[i] )
                        t = 0;
                }
            }
        }
    }
    for (i = 0; i < T; i++)
    {
        sum = 0;
        for (j = 0; j < L[i]; j++)
        {
            c = s[i][j];
            if (n[i] == 1)
            {
                n[i] = 2;
            }
            if (('0' <= c) && (c <= '9'))
            {
                temp = c - '0';
                sum = sum * n[i] + mea[i][temp];
            }
            else if (('A' <= c) && (c <= 'Z'))
            {
                temp = c - 'A' + 10;
                sum = sum * n[i] + mea[i][temp];
            }
            else
            {
                temp = c - 'a' + 36;
                sum = sum * n[i] + mea[i][temp];
            }
        }
        printf("case #%d:\n", i);
        printf("%ld\n", sum);
    }
    return 0;
}
