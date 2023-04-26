#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct st
{
    int d1,d2;
};

int gcd(int m,int n)
{
    if(m<n){int t=m;m=n;n=t;}
    if(n==0)return m;
    else{
    m=m%n;
    return gcd(m,n);
    }

}

int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n,i,e;
    int a[1001]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        a[e] = 1;
    }

    int b[1000],m=0,cnt = 0,j;
    for(i=1;i<=1000;i++)
        if(a[i]) b[m++] = i;
    for(i=0;i<m-1;i++)
        for(j=i+1;j<m;j++)
         if(gcd(b[i],b[j])==1) cnt++;
    printf("case #%d:\n%d\n",t,cnt);

    }
}