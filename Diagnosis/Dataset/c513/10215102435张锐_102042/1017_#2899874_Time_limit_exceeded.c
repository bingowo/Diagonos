#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int Roma[128]={0};
    Roma['I']=1;Roma['V']=5;Roma['X']=10;Roma['L']=50;Roma['C']=100;Roma['D']=500;Roma['M']=1000;
    long long data[100]={0};int j=0;int flag=1;
    for(int i=0;j<strlen(s);i++)
    {
        switch(s[i])
        {
            case '(':flag*=1000;
            case ')':flag/=1000;
            default:data[j++]=Roma[s[i]]*flag;break;
        }
    }
    long long int ans=0;int i;
    for(i=0;i<j-1;j++)
    {
        if(data[i]<data[i+1]) ans-=data[i];
        else ans+=data[i];
    }
    ans+=data[i];
    printf("%lld",ans);
    return 0;
}
