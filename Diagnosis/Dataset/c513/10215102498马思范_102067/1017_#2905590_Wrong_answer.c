#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Roma[128]={0};
int main()
{
    Roma['I']=1;Roma['V']=5;
    Roma['X']=10;Roma['L']=50;
    Roma['C']=100;Roma['D']=500;
    Roma['M']=1000;
    char s[51];scanf("%s",s);
    long long data[100];
    int cnt=0;
    long long flag=1;
    int len= strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')
            flag=flag*1000;
        else if(s[i]==')')
            flag=flag/1000;
        data[cnt]=Roma[s[i]]*flag;
        cnt++;
    }
    long long ans=0;
     for(int i=0;i<cnt-1;i++)
     {
        if(data[i]<data[i+1])
             ans-=data[i];
        else ans+=data[i];
     }
     ans+=data[cnt-1];
     printf("%lld\n",ans);
    return 0;
}