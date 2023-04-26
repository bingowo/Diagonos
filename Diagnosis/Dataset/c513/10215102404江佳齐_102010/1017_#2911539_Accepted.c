#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[51];int j=0;
    scanf("%s",s);
    long long data[100];long long ans=0,flag=1;
    int Roma[128]={0};
    Roma['I']=1;Roma['V']=5;Roma['X']=10;Roma['L']=50;
    Roma['C']=100;Roma['D']=500;Roma['M']=1000;
    for(int i=0;s[i];i++)
    {
        switch(s[i])
        {
            case '(':flag=flag*1000; break;
            case ')':flag=flag/1000; break;
            default: data[j++]=Roma[s[i]]*flag; break;
        }
    }
    for(int i=0;i<j-1;i++)
    {
        if(data[i]<data[i+1]) ans-=data[i];
        else ans+=data[i];
    }
    ans+=data[j-1];
    printf("%lld\n",ans);
    return 0;
}
