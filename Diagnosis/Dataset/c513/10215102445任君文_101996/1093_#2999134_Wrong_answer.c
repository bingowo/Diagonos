#include<stdio.h>
#include<stdlib.h>
unsigned long long mypow(int x, int y)
{
    int i;
    unsigned long long temp=1;
    for(i=0;i<y;i++)
    {
        temp=temp*x;
    }
    return temp;
}
int main()
{
    int num[1010]={0};
    unsigned long long n=0;
    int m=0;
    int i;
    int s=0,t;
    char c;
    while((c=getchar())!='\n')
    {
        num[m]=c-'0';
        m++;
    }
    t=m+1;
    for(i=0;i<m;i++)
    {
        n=n*10+num[i];
        s=s+num[i];
        if(num[i]==9)
        {
            t=i;
        }
    }
    if(s%3==0)
    {
        if((t==m+1)||(t==m-1))
        {
            printf("%llu\n",n+1);
        }
        else
        {
            n=n+mypow(10,m-t-1);
            printf("%llu\n",n);
        }
    }
    else if(s%3!=0)
    {
        if(t!=m+1)
        {
            n=n+mypow(10,m-t-1);
            printf("%llu\n",n);
        }
    }
    return 0;
}