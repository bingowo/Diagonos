#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        char s[61];
        scanf("%s",s);
        int a[128];
        for(int j=0;j<128;j++)a[j]=-1;
        int digit=0,N=1;
        char* p=s;
        a[*p]=1;
        while(*++p)
            if(a[*p]==-1)
        {
            a[*p]=digit;
            digit=digit?digit+1:2;
            N++;
        }
        if(N<2)N=2;
        long long ans=0;
        p=s;
        while(*p)ans=ans*N+a[*p++];
        printf("case #%d:\n%lld\n",i,ans);

    }
    return 0;
}
