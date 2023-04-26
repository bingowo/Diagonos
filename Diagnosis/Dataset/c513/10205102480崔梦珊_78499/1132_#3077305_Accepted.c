#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        ll n,r;
        scanf("%lld %lld",&n,&r);
        printf("case #%d:\n",i);
        if(r<=10)
        {
            ll cnt=0;
            while(n/r!=0)
            {
                cnt=cnt+n%r;
                n=n/r;
            }
            cnt=cnt+n;
            ll ans[10000]={0};
            int flag=0;
            while(cnt/r!=0)
            {
                ans[flag]=cnt%r;
                flag++;
                cnt=cnt/r;
            }
            ans[flag]=cnt;
            //printf("%lld %d",cnt,flag);
            for(int k=flag;k>=0;k--)
            {
                printf("%lld",ans[k]);
            }
            printf("\n");
        }
        else
        {
            char s[10000]={0};
            int cnt=0;
            while(n/r!=0)
            {
                if(n%r<10)
                {
                    s[cnt]='0'+(n%r);
                    cnt++;
                }
                if(n%r>=10)
                {
                    s[cnt]='A'+(n%r)-10;
                    cnt++;
                }
                n=n/r;
            }
            if(n%r<10)
            {
                s[cnt]='0'+(n%r);
            }
            if(n%r>=10)
            {
                s[cnt]='A'+(n%r)-10;
            }
            ll an=0;
            for(int k=0;k<=cnt;k++)
            {
                if(s[k]<='9'&&s[k]>='0')
                {
                    an=an+s[k]-'0';
                }
                if(s[k]<='F'&&s[k]>='A')
                {
                    an=an+s[k]-'A'+10;
                }
            }
            char ans[10000]={0};
            int flag=0;
            while(an/r!=0)
            {
                if(an%r<10)
                {
                    ans[flag]='0'+(an%r);
                    flag++;
                }
                if(an%r>=10)
                {
                    ans[flag]='A'+(an%r)-10;
                    flag++;
                }
                an=an/r;
            }
            if(an%r<10)
            {
                ans[flag]='0'+(an%r);
            }
            if(an%r>=10)
            {
                ans[flag]='A'+(an%r)-10;
            }
            for(int k=flag;k>=0;k--)
            {
                printf("%c",ans[k]);
            }
            printf("\n");
        }

    }
}
