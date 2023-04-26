#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
long long toNum(char s[])
{
    int len = strlen(s);
    char c = s[len-1];
    long long ans = 0;
    switch(c)
    {
        case 'I':ans = 1;break;
        case 'V':ans = 5;break;
        case 'X':ans = 10;break;
        case 'L':ans = 50;break;
        case 'C':ans = 100;break;
        case 'D':ans = 500;break;
        case 'M':ans = 1000;break;
        default :ans = 0;
    }
    for(int i = len-1;i>=0;i--)
    {
        if(s[i]=='(')
        {
            ans*=1000;
        }
    }
    return ans;
}
int main()
{
    char s[60];memset(s,0,60*sizeof(char));
    scanf("%s",s);
    int slen = strlen(s);
    long long n[60];memset(n,0,60*sizeof(long long));
    char sn[60][10];memset(sn,0,60*10*sizeof(char));
    int i = 0,cnt = 0,k = 0;;
    for(i = 0;i<slen;i++)
    {
        if(isalpha(s[i]))
        {
            sn[cnt][k] = s[i];
            cnt++;
            k = 0;
        }
        else if((s[i]=='('))
        {
            sn[cnt][k] = s[i];
            k++;
        }
    }

    for(int j = 0;j<cnt;j++)
    {
        n[j] = toNum(sn[j]);
        //printf("%lld %s\n",n[j],sn[j]);
    }

    long long ans = 0;
    for(int j = 0;j<cnt;j++)
    {
        if(n[j]<n[j+1])
        {
            ans-=n[j];
        }
        else
        {
            ans+=n[j];
        }
    }
    printf("%d",ans);
    return 0;
}
