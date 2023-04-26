#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[50];
    long long r=0,mul=1,sign=-1,sum=0,t=0;
    long long arr[91]={0},at[50]={0};
    arr['I']=1,arr['V']=5,arr['X']=10,arr['L']=50,arr['C']=100,arr['D']=500,arr['M']=1000;
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
       if(s[i]=='(') mul*=1000,sign=0;
       else if(s[i]==')')
        {
            sign=-1;
            if(s[i+1]!=')')
            {
                at[t++]=sum*mul;
                sum=0;
                mul=1;
            }
        }
        else
        {
            if(sign==-1) at[t++]=arr[s[i]];
            else
                sum+=arr[s[i]];
        }
    }
    for(int i=0;i<t;i++)
    {
        if(at[i]==at[i+1]||at[i]==at[i-1])
        {
            r+=at[i];
        }
        else if(at[i+1]>at[i]&&i+1<t)
        {
            r-=at[i];
        }
        else if(at[i+1]<at[i]&&i+1<t||i+1==t)
        {
            r+=at[i];
        }
    }
    printf("%lld",r);
    return 0;
}