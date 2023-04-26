#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roma[128]={0};
    long long t[1000];
    int i,k=0;
    long long f=1;
    long long sum=0;
    roma['I']=1;roma['V']=5;roma['X']=10;roma['L']=50;roma['C']=100;roma['D']=500;roma['M']=1000;
    char s[1000];
    scanf("%s",s);
    for(i=0;s[i];i++)
    {
        switch(s[i])
        {
            case'(':f=f*1000;break;
            case')':f=f/1000;break;
            default:t[k++]=roma[s[i]]*f;break;
        }

    }

    for(i=0;i<k-1 && (k-1)>=0;i++)
    {
        if(t[i]<t[i+1])sum=sum-t[i];
        else sum=sum+t[i];
    }
    sum=sum+t[i];
    printf("%lld",sum);
    return 0;
}
