#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int weishu(int a,int b)
{
    char c[1000];
    char s[1000];
    int i,j;
    for(i=0;a>0;i++)
    {
        c[i]=a%2+48;
        a=a/2;
    }
    for(j=0;b>0;j++)
    {
        s[j]=b%2+48;
        b=b/2;
    }
    if(i==j)
        c[i]=s[j]='\0';
    else
    {
        if(i>j)
        {
            for(;i<j;i++)
                c[i]='0';
            c[i]=s[j]='\0';
        }
        else
        {
            for(;j<i;j++)
                s[j]='0';
            c[i]=s[j]='\0';
        }
    }
    int l,k,r=0;
    for(l=0,k=0;c[l]||s[k];l++,k++)
    {
        if(c[l]!=s[k])
            r=r+1;
    }
    return r;
}

int main()
{
    int T;
    scanf("%d",&T);
    int a[T][2];
    int i,j;
    for(i=0;i<T;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<T;i++)
    {
        printf("%d\n",weishu(a[i][0],a[i][1]));
    }
}
