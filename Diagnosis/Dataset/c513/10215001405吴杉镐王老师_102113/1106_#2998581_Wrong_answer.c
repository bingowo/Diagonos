#include <stdio.h>
#include <string.h>
#define M 1000000007

int main()
{
    char s[1005];
    scanf("%s",s);
    int l=strlen(s);
    long long res=1;
    for(int i=0;i<l;i++)
    {
        if(i==0 && l!=1)
        {
            if(s[0]!=s[1])
                res=res*2%M;
        }
        else if(i==l-1 && l!=1)
        {
            if(s[l-1]!=s[l-2])
                res=res*2%M;
        }
        else
        {
            if(s[i]!=s[i-1] && s[i]!=s[i+1])
                res=res*3%M;
            else if(s[i]==s[i-1] && s[i]!=s[i+1])
                res=res*2%M;
            else if(s[i]==s[i+1] && s[i]!=s[i-1])
                res=res*2%M;
            else if(s[i]!=s[i+1] && s[i+1]==s[i-1])
                res=res*2%M;
        }
    }
    printf("%lld\n",res);
}
