#include<stdio.h>
int main()
{
    int question,s,i;
    scanf("%d",&question);
    for(s=0;s<question;s++)
    {
        printf("case #%d:\n",s);
        char s[61];
        int a[128];
        long long ans=0;
        scanf("%s",s);
        for (i=0;i<128;i++)
            a[i]=-1;
        int digit=0,N=1,i; char *p=s;
        a[*p]=1;
        while (*++p)
            if (a[*p]==-1)
            {
                a[*p]=digit;
                digit=digit?digit+1:2;
                 N++;
            }
        if (N<2)
            N=2;
        p=s;
        while (*p)
            ans=ans*N+a[*p++];
        printf("%lld\n",ans);

    }
    return 0;
}

