#include<stdlib.h>
#include<stdio.h>

int len(int n)
{
    int j,k;
    int temp=1;
    int len=1;
    int s[10000];int t[10000];
    for(j=0;n>0;j++)
    {
        s[j]=n%2;
        n=n/2;
    }
    for(k=0;j>0;k++,j--)
    {
        t[k]=s[j-1];
    }
    for(k=0;t[k+1];k++)
    {
        while(t[k]!=t[k+1])
            temp++;
        if(len<temp) len=temp;
    }
}
int main()
{
    int T,i,n,len;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        len=len(n);
        printf("case #%d:\n%d",i,len);
    }
    return 0;
}
