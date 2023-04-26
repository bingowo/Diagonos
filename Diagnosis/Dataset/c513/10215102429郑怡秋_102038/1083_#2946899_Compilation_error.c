#include <stdio.h>
#include <stdlib.h>
void add(int a[])
{
    if(a[0]==0) a[0]=1;
    else 
    {
        int i=1;
        while(a[i]!=0) a[i]=~a[i],i++;
        a[i]=1;
    }
}
void add2(int a[],int b[])
{
    int carry=0;
    
    
}
void mul(int a[],int x)
{
    int b[10000]={0};
    add(b);
    for(int i=0;i<x;i++)
    {
        
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a[10000];
        int m;
        scanf("%d",&m);
        int x=m;
        int j=0;
        while(x)
        {
            a[j++]=x&1;
            x>>=1;
        }
        mul(a,x);
        printf("case #%d:\n%d\n",i,tump);
    }
    return 0;
}