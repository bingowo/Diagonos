#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define M 1000000
int main()
{
    char str[M] = { 0 };
    int number[30] = { 0 }, numberp[30] = { 0 };
    int big[30] = { 0 }, bigp[30] = { 0 };
    int small[30] = { 0 }, smallp[30] = { 0 };
    int i = 0, j = 0, k = 0, temp = 0, t = 0, MAX = 0;
    int L = 0, R = 0;
    int n = 0;
    scanf("%s", str);
    n = strlen(str);
    for (i = 0; i < n; i++)
    {
        if (('A' <= str[i]) && (str[i] <= 'Z'))
        {
            temp = str[i] - 'A';
            if (big[temp] == 0)
            {
                big[temp]++;
                bigp[temp] = i;
                R = i;
                if (R == n-1)
                {
                    t = R - L + 1;
                    if (t > MAX)
                    {
                        MAX = t;
                        j = L;
                    }
                }
            }
            else
            {
                big[temp] = 1;
                t = R - L + 1;
                if (t > MAX)
                {
                    MAX = t;
                    j = L;
                }
                for (k = L; k < bigp[temp]+1; k++)
                {
                    t = str[k] - '0';
                    big[t] = 0;
                }
                L = bigp[temp]+1;
                bigp[temp] = i;
            }
        }
        else if (('a' <= str[i]) && (str[i] <= 'z'))
        {
            temp = str[i] - 'a';
            if (small[temp] == 0)
            {
                small[temp]++;
                smallp[temp] = i;
                R = i;
                if (R == n-1)
                {
                    t = R - L + 1;
                    if (t > MAX)
                    {
                        MAX = t;
                        j = L;
                    }
                }
            }
            else
            {
                small[temp] = 1;
                t = R - L + 1;
                if (t > MAX)
                {
                    MAX = t;
                    j = L;
                }
                for (k = L; k < smallp[temp]+1; k++)
                {
                    t = str[k] - '0';
                    small[t] = 0;
                }
                L = smallp[temp]+1;
                small[temp] = i;
            }
        }
        else if (('0' <= str[i]) && (str[i] <= '9'))
        {
            temp = str[i] - '0';
            if (number[temp] == 0)
            {
                number[temp]++;
                numberp[temp] = i;
                R = i;
                if (R == n-1)
                {
                    t = R - L + 1;
                    if (t > MAX)
                    {
                        MAX = t;
                        j = L;
                    }
                }
            }
            else
            {
                number[temp] = 1;
                t = R - L + 1;
                if (t > MAX)
                {
                    MAX = t;
                    j = L;
                }
                for (k = L; k <numberp[temp]+1; k++)
                {
                    t = str[k] - '0';
                    number[t] = 0;
                }
                L = numberp[temp]+1;
                numberp[temp] = i;
            }
        }
    }
    for (i = j; i < MAX; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}