#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(char *c)
{
    int i,j,k=0;
    for(i=0;c[i];i++)
        k=k+1;
    int a[k-1];
    int l=1,m;
    for(j=0;j<k;j++)
    {
        for(i=j;c[i]&&c[i+1];i++)
            {
                if(c[i]!=c[i+1])
                    l=l+1;
                else
                    {
                        a[j]=l;
                        break;
                    }
            }
    }
    for(i=1,m=a[0];i<k-1;i++)
    {
        if(a[0]<a[i])
            m=a[i];
    }
    return m;
}

void reverse(char *c)
{
    int i,j,l=0;
    char s;
    for(i=0;c[i];i++)
        l=l+1;
    for(i=0,j=l-1;i<j;i++,j--)
    {
        s=c[i];
        c[i]=c[j];
        c[j]=s;
    }
}

int main()
{
    int N,i,k;
    scanf("%d",&N);
    int a[N];
    char c[N][31];//存储数字的二进制
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);//存储数字
    for(k=0;k<N;k++)
    {
        for(i=0;a[k]>0;i++)
        {
            c[k][i]=a[k]%2+30;
            a[k]=a[k]/2;
            if(a[k]==0)
                reverse(c[k]);//对数组的一行进行反转
        }
    }
    for(k=0;k<N;k++)
        printf("case #%d:\n%d\n",k,max(c[k]));
    }
