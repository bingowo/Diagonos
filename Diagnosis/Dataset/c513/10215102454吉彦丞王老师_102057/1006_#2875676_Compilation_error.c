#include<stdio.h>
#include<string.h>
int main()
long long int zhishu(int a,long long int b)
{
    for(int i=0;i<a;i++)
    {
        b=b*b;
    }
    return b;
}
{
    int number;
    scanf("%d",&number);
    char s[number][100];
    long long int result[number];
    for(int i=0;i<number;i++)
    {
        int d=0;
        scanf("%s",s[i]);
        int length=strlen(s[i]);
        for(int j=0;j<strlen(s[i]);j++)
        {
            if(s[i][j]=='-1')
            {
                d=d+(-1)*zhishu(strlen(s[i],))
            }
        }
    }
}