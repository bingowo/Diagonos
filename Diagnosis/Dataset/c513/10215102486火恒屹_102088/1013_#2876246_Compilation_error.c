#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long mypow(int a,int b)
{
    long long sum=1;
    for(int i=0;i<b;i++)
    {
        sum=sum*a;
    }
    return sum;
}

long long myabs(long long a)
{
    if(a<0)
        return -a;
    else
        return a;
}

void approxi(int *a,int *b)
{
    for(int i=2;i<=a;i++)
    {
        if((*a % i==0)&&(*b % i==0))
        {
            *a=*a/i;
            *b=*b/i;
            i=i-1;
        }
    }
}
int main()
{
        char c[100]={'\0'};
        scanf("%s",&c);
        int b=strlen(c);
        long long sum=0;
        int point=b;
        for(int j=0;j<b;j++)
        {
            if(c[j]=='.')
                point=j;
        }
        long long ans=mypow(3,point-1);
        printf("CAONIMA   %lld\n",ans);//test
        for(int j=0;j<point;j++)
        {
            if(c[j]=='2')
                {sum=sum-ans;
                ans=ans/3;}
            else if(c[j]=='1')
                {sum=sum+ans;
                ans=ans/3;}
        }
        if(point==b)
        printf("%lld",sum);
        else if(point<b)
        {
            ans=mypow(3,strlen(c)-point)
            long long deno=ans;
            long long nume=0;
            for(int j=point+1;j<strlen(c);j++)
            {
            if(c[j]=='2')
                {ans=ans/3;
                nume=nume-ans;}
            else if(c[j]=='1')
                {ans=ans/3;
                nume=nume+ans;}
            }
            int flagnume=1;
            if(nume<0) flagnume=-1;
            if((nume<0)&&(sum>0))
            {
                nume=deno+nume;
                sum=sum-1;
            }
            if((nume>0)&&(sum<0))
            {
                nume=deno-nume;
                sum=sum+1;
            }
            if(nume<0)
                nume=-nume;
            for(int i=2;i<=nume;i++)
            {
                if((nume % i==0)&&(deno % i==0))
                {
                    nume=nume/i;
                    deno=deno/i;
                    i=i-1;
                }
            }
            if(sum!=0) printf("%lld %lld %lld",sum,nume,deno);
            else if((sum==0)&&(flagnume==1)) printf("%lld %lld",nume,deno);
            else if((sum==0)&&(flagnume==-1)) printf("%lld %lld",-nume,deno);
        }
    return 0;
}
