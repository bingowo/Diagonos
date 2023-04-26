#include<stdio.h>
#include<string.h>



int main()
{
    char s[55];
    scanf("%s",s);
    int len;
    len=strlen(s);
    long long int ans=0;
    int Roma[128]={0};
    Roma['I']=1;Roma['V']=5;Roma['X']=10;Roma['L']=50;
    Roma['C']=100;Roma['D']=500;Roma['M']=1000;
    long long int data[55];
    long long int flag=1;
    int cnt=0;
    for(int i=0;i<len;i++)
    {
        switch(s[i])
        {
            case '(':flag = flag*1000;break;
            case ')':flag = flag/1000;break;
            default:data[cnt]=Roma[s[i]]*flag;cnt++;break;
                
        }
    }
    
    for(int i=0;i<cnt-1;i++)
    {
        if(data[i]<data[i+1])
            ans-=data[i];
        else
            ans+=data[i];
    }
    ans+=data[cnt-1];
    printf("%lld\n",ans);
    return 0;
    
}


