#include<stdio.h>
int main()
{
    int a;
    scanf("%d\n",&a);
    char s[a][61];
    for(int i=0;i<a;i++)
    {
        scanf("%s",s[i]);
        int b[128];
        for(int j=0;j<128;j++)
        {
            b[j]=-1;
        }
        int digit=0,N=1,k;char *p=s[i];
        b[*p]=1;
        while(*++p)
        {
            if(b[*p]==-1)
            {
                b[*p]=digit;
                digit=digit?digit+1:2;
                N++;
            }
        }
        if(N<2)
        {
            N=2;
        }
        long long int ans=0;
        p=s[i];
        while(*p)
        {
            ans=ans*N+b[*p++];
        }
        printf("case #");
        printf("%d",i);
        printf(":\n");
        printf("%lld",ans);
    }
    return 0;

    
}