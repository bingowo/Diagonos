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
    reslen = 0;
    for (i = 0;i < strlen(s);i++)
    {
        //memset(temp, 0, sizeof(temp));        指针不能sizeof，mmp
        memset(temp, 0, 1000001 * sizeof(char));
        k = 0;              //temp里元素的个数
        for (j = i;j < strlen(s);j++)
        {
            if (strchr(temp,s[j])==NULL)
            {
                temp[k++] = s[j];
            }
            else
                break;
        }
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
