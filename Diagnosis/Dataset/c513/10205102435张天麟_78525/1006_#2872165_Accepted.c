#include<stdio.h>
#include<string.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int j;
        char s[19];
        scanf("%s",s);
        long long ans=0;
        for(j=0;j<strlen(s);j++)
        {
            ans*=3;
            if(s[j]=='1')ans+=1;
            if(s[j]=='0')continue;
            if(s[j]=='-')ans-=1;
        }
        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }
    return 0;
}
