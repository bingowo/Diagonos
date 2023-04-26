#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 1000
int a[maxn], b[maxn];
int myStrcmp(const char str1[], const char str2[])
{
    if(strlen(str1) > strlen(str2))
        return 1;
    if(strlen(str1) == strlen(str2))
        return strcmp(str1, str2);
    return 0;
}

void sub(char str1[], char str2[])
{
    //逆序存入
    for(int i = strlen(str1) - 1, j = 0; i >= 0; i--)
        a[j++] = str1[i] - '0';
    for(int i = strlen(str2) - 1, j = 0; i >= 0; i--)
        b[j++] = str2[i] - '0';
    //计算
    int bit = 0;
    for(int i = 0; i < maxn; i++)
    {
        a[i] -= bit;
        if(a[i] < b[i])
        {
            a[i] += 10;
            bit = 1;
        }
        else
            bit = 0;
        b[i] = a[i] - b[i];
    }
    //输出
    int i;
    for(i = maxn - 1; i >= 0 && b[i] == 0; i--);
    if(i >= 0)
        for( ; i >= 0; i--)
            printf("%d",b[i]);
    else
        printf("0");
    printf("\n");
}

int main()
{
    char str1[maxn], str2[maxn];
    while(scanf("%s %s",str1,str2)!=EOF)
    {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    if(myStrcmp(str1, str2)>0 || myStrcmp(str1,str2)==0)
    {
        sub(str1, str2);
    }
    else
    {
        printf("-");
        sub(str2, str1);
    }
    }
    return 0;
}
