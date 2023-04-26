#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void gys(int s,int sum)
{
    int n=sum,m=s,temp;
    while(m!=0)
    {
        temp=n%m;
        n=m;
        m=temp;
    }
    if(n==0)n=1;
    s/=n;sum/=n;
    printf("%d/%d",s,sum);
}

int main()
{
    int n,s;scanf("%d %d",&n,&s);
    int i,m=1,a[n+1],sum,h;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[m]>a[i])m=i;
    }
    int line[1001],k=0;
    for(h=a[m]+1;s>0;h++)
    {
        sum=0;
        for(i=1;i<=n;i++)
        if(a[i]<h)sum++;
        s-=sum;
    }h--;
    if(s==0)printf("%d",h);
    else
    {
        h--;
        s+=sum;
        printf("%d+",h);
        gys(s,sum);
    }
}