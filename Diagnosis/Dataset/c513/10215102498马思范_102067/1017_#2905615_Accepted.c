#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int R[128]={0};
int main()
{
    R['I']=1;R['V']=5;
    R['X']=10;R['L']=50;
    R['C']=100;R['D']=500;
    R['M']=1000;
    char s[51];
    scanf("%s",s);
    long long int data[100];
    int cnt=0;
    long long int flag=1;

    for(int i=0;s[i];i++)
    {
      switch(s[i])
      {
        case '(': flag=flag*1000;break;
        case ')': flag=flag/1000;break;
        default: data[cnt++]=R[s[i]]*flag;break;
       }
    }
    long long int ans=0;
     for(int i=0;i<cnt-1;i++)
     {
        if(data[i]<data[i+1])
             ans-=data[i];
        else ans+=data[i];
     }
     ans+=data[cnt-1];
     printf("%lld",ans);
     return 0;
}