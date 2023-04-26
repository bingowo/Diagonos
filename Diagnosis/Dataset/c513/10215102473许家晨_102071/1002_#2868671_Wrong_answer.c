#include<stdio.h>
#include<string.h>
int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while(T)
    {

        char s[61];
        scanf("%s",s);
        int a[128];
        int i;
        for(i=0; i<128; i++)
        {
            a[i]=-1;
        }
        int digit=0,N=1;
        char *p=s;
        a[*p]=1;
        while(*++p)
        {
            if(a[*p]==-1)
            {
                a[*p]=digit;
                digit=digit?digit+1:2;
                N++;
            }
            if(N<2)N=2;

        }
        long long ans=0;
        p=s;
        while(*p)
        {
            ans=ans*N+a[*p++];
        }
        printf("case #%d:\n%d\n",cnt,ans);
        cnt++;
		T-=1;


    }
    return 0;
}