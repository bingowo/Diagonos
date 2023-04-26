#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100];
    int b[128]={0},data[100]={0};
    int k=0;
    long long ans=0;
    scanf("%s",a);
    int len=strlen(a);
    b['I']=1;
    b['V']=5;
    b['X']=10;
    b['L']=50;
    b['C']=100;
    b['D']=500;
    b['M']=1000;
    int flag=1;
    for(int i=0;i<len;i++)
    {
        switch(a[i])
        {
        case '(':
            flag=flag*1000;
            break;
        case ')':
            flag=flag/1000;
        default:
            data[k++]=b[a[i]]*flag;
        }
    }
    k--;
    for(int i=0;i<k;i++)
    {
        if(data[i]<data[i+1])
            ans=ans-data[i];
        else
            ans=ans+data[i];
    }
    ans=ans+data[k];
    printf("%lld",ans);
    return 0;
}
