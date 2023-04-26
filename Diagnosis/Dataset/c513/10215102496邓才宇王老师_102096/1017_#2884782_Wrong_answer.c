#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int R[128]={0};
    R['I']=1;
    R['V']=5;
    R['X']=10;
    R['L']=50;
    R['C']=100;
    R['D']=500;
    R['M']=1000;
    long long int s1[51]={0};
    double flag=1;
    int j=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
        {
            flag=flag*1000;
        }
        if(s[i]==')')
        {
            flag=flag/1000;
        }
        else
        {
            s1[j++]=R[s[i]]*flag;
        }
    }
    long long int ans=0;
    for(int k=0;k<j+1;k++)
    {
        if(s1[k]<s1[k+1]) ans=ans-s1[k];
        else ans=ans+s1[k];
    }
    printf("%lld",ans);
}
