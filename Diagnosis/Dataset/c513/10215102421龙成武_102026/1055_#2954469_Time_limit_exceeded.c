#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void findcore(char* s, char* core);
int main()
{
    int i, j, k,hash[1000],reslen;
    char s[1000001], * temp, * res, * p,core[1000];
    scanf("%s", s);
    findcore(s, core);
    memset(hash, 0, sizeof(hash));
    temp = (char*)malloc(1000001 * sizeof(char));
    res = (char*)malloc(1000001 * sizeof(char));
    reslen = 0;
    for (i = 0;i < strlen(s);i++)
    {
        memset(hash, 0, sizeof(hash));
        memset(temp, 0, 1000001 * sizeof(char));
        k = 0;              //temp里元素的个数
        for (j = i;j < strlen(s);j++)
        {
            if(hash[s[j]]==0)
            {
                temp[k++] = s[j];
                hash[s[j]] = 1;
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
void findcore(char* s, char* core)
{
    int i, j;j = 0;
    for (i = 0;i < strlen(s);i++)
    {
        if (strchr(core, s[i]) == NULL)
        {
            core[j++] = s[i];
        }
    }
}