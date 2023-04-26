#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void read(int i,int n,int m,int dep,int t,long long int a[])
{
    if(dep==n&&t==m)
    {
        a[0]++;
        return;
    }
    else if(dep==n&&t<m)
        return;
    else
    {
        if(t>=m)
        {
            long long int i=1;
            do
            {
                i=i*2;
                dep++;
            }
            while(dep<n);
            a[0]+=i;
            return;
        }
        read(1,n,m,dep+1,t+1,a);
        read(0,n,m,dep+1,0,a);
    }
}
int main()
{
    int n,m;
    long long int a[3];
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        a[0]=0;
        if(n==-1&&m==-1)
            break;
        read(0,n,m,1,0,a);
        read(1,n,m,1,1,a);
        printf("%d\n",a[0]);
    }
}
