#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int base,int n)
{
    int i,p;
    p=1;
    for(i=1;i<=n;i++)
        p=p*base;
    return p;
}
int main()
{
    char s[61];
    scanf("%s",&s);
    int len=strlen(s);
    char temp[61];
    temp[0]=1;
    int num=1;
    for(int i=1;i<strlen(s);i++)
    {
        for(int j=0;j<i;j++)
        {
            if(s[i]==s[j])
            {
                temp[i]=temp[j];
                break;
            }
            if(num=1) temp[i]=0;
            if(num!=1&&j==i-1) temp[i]=++num;
        }
    }
    int min=0;
    for(int i=0;i<len;i++)
    {
        min+=temp[i]*power(num+1,len-i-1);
    }
    printf("%d\n",min);
    return 0;
}
