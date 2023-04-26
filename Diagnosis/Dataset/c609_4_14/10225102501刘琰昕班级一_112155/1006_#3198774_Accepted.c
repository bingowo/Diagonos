#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[61];scanf("%s",s);
        int a[128];for(int i=0;i<128;i++)a[i]=-1;
        char *p=s+1;int R=2;
        a[s[0]]=1;
        while(a[*p]!=-1)p++;a[*p++]=0;
        while(*p)
        {
            if(a[*p]==-1)a[*p]=R++;
            p++;
        }
        p=s;long long ans=0;
        while(*p)
        {
            ans=ans*R+a[*p++];
        }
        printf("case #%d:\n%lld\n",i,ans);
    }

    return 0;
}
