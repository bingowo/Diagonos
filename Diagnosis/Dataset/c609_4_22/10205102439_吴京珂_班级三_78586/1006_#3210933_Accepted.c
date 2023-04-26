#include <stdio.h>
#include <stdlib.h>

int _3to10(char s[])
{
    int a[128];
    for(int j=0; j<128; j++) a[j]=-1;
    int cnt=0;
    for(int j=0; s[j]; j++)
    {
        if(a[s[j]]==-1)
        {
            cnt++;
            if(cnt==1) a[s[j]]=1;
            else if(cnt==2) a[s[j]]=0;
            else a[s[j]]=cnt-1;
        }
    }
    if(cnt<2) cnt=2;//二进制

    long long int ans=0;
    for(int j=0; s[j]; j++)
    {
        ans=ans*cnt+a[s[j]];
    }

    printf("%lld\n",ans);

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        char s[100];
        scanf("%s",s);
        printf("case #%d:\n",i);
        _3to10(s);
    }
    return 0;
}