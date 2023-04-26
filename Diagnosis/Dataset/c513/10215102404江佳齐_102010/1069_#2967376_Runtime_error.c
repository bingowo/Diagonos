#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int pow(int a,int b)
{
    long long int sum=1;
    for(int i=0;i<b;i++) sum=sum*a;
    return sum;
}
long long int turn(long long int n)
{
    int a[11];int len=0;
    long long int m=0;
    for(int i=0;;i++)
    {
        if(n==0) break;
        a[i]=n%10;
        n=n/10;
        len+=1;
    }
    for(int i=0;i<len;i++)
    {
        m=m+a[i]*(pow(10,len-1-i));
    }
    return m;
}
int main()
{
    long long int n,m,s;
    int count=0;
    scanf("%d",&n);
    m=turn(n);
    s=n+m;
    while(s!=turn(s))
    {
        n=s;
        m=turn(n);
        s=n+m;
        count+=1;
    }
    printf("%d %lld\n",count+1,s);
    return 0;
}
