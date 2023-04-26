#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
int main()
{
    char s[1000]={0};
    scanf("%s",s);
    int len=strlen(s);
    if(len==1)
    {
        printf("1");
        return 0;
    }
    ll res=1;
    for(int i=0;i<len;i++)
    {
        if(i==0)
        {
            if(s[i]!=s[i+1]) res=res*2%1000000007;
        }
        else if(i==len-1)
        {
            if(s[i]!=s[i-1]) res=res*2%1000000007;
        }
        else
        {
            if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
            {
                res=res*3%1000000007;

            }
            if(s[i]!=s[i-1]&&s[i]!=s[i+1]&&s[i-1]==s[i+1])
            {
                res=res*2%1000000007;

            }
            if(s[i]==s[i-1]&&s[i]!=s[i+1])
            {
                res=res*2%1000000007;

            }
            if(s[i]!=s[i-1]&&s[i]==s[i+1])
            {
                res=res*2%1000000007;

            }
        }



    }
    printf("%lld\n",res);
}

