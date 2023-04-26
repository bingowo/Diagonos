#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        char s[61];
        scanf("%s",s);

        int a[128];
        for(int j=0; j<128; j++) a[j]=-1;

        int cnt=0;
        for(int j=0; s[j]; j++)
        {
            if(a[s[j]]==-1)
            {
                cnt++;
                if(cnt==1) a[s[j]]=cnt;
                else if(cnt==2) a[s[j]]=0;
                else a[s[j]]=cnt-1;
            }
        }
        //for(int i=0;i<128;i++) printf("%d\n",a[i]);
        if(cnt<2) cnt=2;
        long long int ans=0;

        for(int j=0; s[j]; j++)
        {
            ans=a[s[j]]+ans*cnt;
            //printf("%d\n",a[s[j]]);
        }

        printf("case #%d:\n",i);
        printf("%lld\n",ans);
    }

    //printf("Hello world!\n");
    return 0;
}
