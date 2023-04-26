#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    char s[61];
    char a[129];
    for(int cas=0;cas<T;cas++)
    {
        scanf("%s",s);
        memset(a,-1,sizeof(a));
        int R=0;a[s[0]]=1;
        for(int j=1;j<strlen(s);j++)
        {
            if(a[s[j]]==-1)
            {
                a[s[j]]=R;
                if(R==0) R=2;
                else if(R>0) R++;
            }
        }
        if(R<2) R=2;
        long long ans=0;
        for(int i=0;i<strlen(s);i++)
        {ans=ans*R+a[s[i]];}
        printf("case #%d:\n%lld\n",cas,ans);
    }
    return 0;
}