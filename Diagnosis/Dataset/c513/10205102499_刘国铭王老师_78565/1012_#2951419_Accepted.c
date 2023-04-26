#include <stdio.h>
#include <stdlib.h>

char s[1000];
long long res[1000];

long long trans(char *s,long long start,long long end)
{
    long long ans=0;
    for(long long i=start;i<=end;i++)
    {
        ans*=10;
        ans+=s[i];
    }
    return ans;
}

int main()
{
    long long a=0,b=0;
    long long nowa,nowb;
    int flag=1;
    scanf("%s",&s);
    long long len=strlen(s);
    for(long long i=0;i<len;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        s[i]=s[i]-'0';
    }
    if(s[len-1]=='i')
    {
        if(s[len-2]=='+' || s[len-2]=='-')
        {
            if(s[len-2]=='+') b=1;
            if(s[len-2]=='-') b=-1;
            if(len-2!=0)
            {
                if(s[0]=='-') a=-trans(s,1,len-3);
                else a=trans(s,0,len-3);
            }
        }
        else
        {
            for(long long j=len-1;j>=0;j--)
            {
                if(s[j]=='+')
                {
                    if(s[0]=='-')
                        a=-trans(s,1,j-1);
                    else
                        a=trans(s,0,j-1);
                    b=trans(s,j+1,len-2);
                    flag=2;
                }
                if(s[j]=='-' && flag==1)
                {
                    if(j==0)
                    {
                        a=0;
                        b=-trans(s,j+1,len-2);
                    }
                    else
                    {
                        if(s[0]=='-')
                            a=-trans(s,1,j-1);
                        else
                            a=trans(s,0,j-1);
                        b=-trans(s,j+1,len-2);
                    }
                    flag=3;
                }
            }
            if(flag==1)
                b=trans(s,0,len-2);
        }
    }
    else
    {
        if(s[0]=='-')
            a=-trans(s,1,len-1);
        else
            a=trans(s,0,len-1);
    }
    if(len==1 &&s[0]=='i') b=1;
    if(a==0 && b==0) printf("0");
    long long k=1;
    while(a!=0 || b!=0)
    {
        nowa=a%2;
        nowb=b%2;
        res[k]=(nowa&1)^(nowb&1);
        long long tempa=-a+b,tempb=-a-b;
        a=tempa;
        b=tempb;
        if(a%2==1 || a%2==-1)
        {
            a++;
            b++;
        }
        a/=2;
        b/=2;
        k++;
    }
    for(long long i=k-1;i>0;i--)
        printf("%lld",res[i]);
    return 0;
}
