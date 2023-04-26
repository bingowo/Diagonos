#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* c)
{
    int i,j;
    char s;
    for(i=0,j=strlen(c)-1;i<j;i++,j--)
    {
        s=c[i];
        c[i]=c[j];
        c[j]=s;
    }
}

int weishu(int a,int b)
{
    char c1[1000],c2[1000];
    int i,r=0,j;
    for(i=0;a>0;i++)
    {
        c1[i]=a%2+48;
        a=a/2;
    }
    for(i=0;b>0;i++)
    {
        c2[i]=b%2+48;
        b=b/2;
    }
    reverse(c1);
    reverse(c2);
    for(i=0,j=0;c1[i]&&c2[j];i++,j++)
    {
        if(c1[i]!=c2[j])
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