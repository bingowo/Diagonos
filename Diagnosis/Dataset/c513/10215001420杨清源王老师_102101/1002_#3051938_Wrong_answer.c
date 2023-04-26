#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cas=0;
    for(cas=0; cas<T; cas++)
    {
        char s[60];
        scanf("%s",s);
        int a[128];
        for(int i=0; i<128; i++)
            a[i]=-1;
        int len=strlen(s);
        int tmp=0;
        int cnt=1;
        a[s[0]]=1;
        for(int i=1; i<len; i++)
        {
            if(a[s[i]]==-1)
            {
                if(tmp==0)
                {
                    a[s[i]]=tmp;
                    tmp++;
                }
                else
                    a[s[i]]=tmp;
                tmp++;
                cnt++;
            }
        }
        int ans=0;
        for(int i=0; i<len; i++)
        {
            ans*=cnt;
            ans+=a[s[i]];
        }
        printf("case #%d:\n",cas);
        printf("%d",ans);
    }
}
