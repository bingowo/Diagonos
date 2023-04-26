#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k,templen,reslen;
    char s[1000001],*temp,*res,*p;
    scanf("%s", s);
    temp = (char*)malloc(1000001 * sizeof(char));
    res = (char*)malloc(1000001 * sizeof(char));
    reslen = 1;
    for (i = 0;i < strlen(s);i++)
    {
        temp[0] = s[i];
        k = 1;              //temp里元素的个数
        for (j = i+1;j < strlen(s);j++)
        {
            if (s[j] != s[j - 1])
            {
                temp[k++] = s[j];
            }
            else
                break;
        }
        temp[k] = 0;
        if (k > reslen)
        {
            p = res;
            res = temp;
            temp = p;
            reslen = k;
        }
    }
    puts(res);
    return 0;
}
