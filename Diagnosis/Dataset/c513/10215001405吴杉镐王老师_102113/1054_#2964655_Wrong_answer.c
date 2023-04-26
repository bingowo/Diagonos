#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l,cnt[300];
char s[1000005];

int main()
{
    scanf("%s",s+1);
    l=strlen(s+1);
    for(int i=0;i<256;i++)
        cnt[i]=0;
    int L=0,ans=0,ansL,ansR;
    for(int R=1;R<=l;R++)
    {
        cnt[s[R]]++;
        while(cnt[s[R]]>1 && L<R)
            cnt[s[++L]]--;
        if(R-L>ans)
        {
            ans=R-L;
            ansR=R;
            ansL=L;
        }
    }
    for(int i=ansL+1;i<=ansR;i++)
        putchar(s[i]);
    return 0;
}