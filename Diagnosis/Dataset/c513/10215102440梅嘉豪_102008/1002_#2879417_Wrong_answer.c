#include <stdio.h>
#define N0 128
#define N1 60
int main()
{
    char s[N1+1],*p;
    int N=1,T,a[N0];
    long long ans=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        p=s;
        for(int j=0;j<128;j++)  a[j]=-1;
        a[*p]=1;
        while(*++p)
        {
            if(a[*p]==-1)
            {
                a[*p]=N==1?0:N;
                N++;
            }
        }
        ans=0;
        p=s;
        while(*p)   
        {
            ans=a[*p++]+ans*N;
        }
        printf("case #%d",i);
        printf(":\n%lld\n",ans);
    }
}