#include<stdio.h>
#include<string.h>
int main()
{
    int w[33];
    w['I']=1;
    w['V']=5;
    w['X']=10;
    w['L']=50;
    w['C']=100;
    w['D']=500;
    w['M']=1000;
    long long flag=1;
    long long cnt=0;
    long long ans=0;
    long long data[51];
    char q[51];
    scanf("%s\n",q);
    for(int i=0;i<strlen(q);i++)
    {
        switch(q[i])
        {
        case '(':
            flag=flag*1000;
            break;
        case ')':
            flag=flag/1000;
            break;
        default:
            data[cnt]=w[q[i]]*flag;
            cnt++;
            break;

        }
    }
    for(int i=0;i<=cnt;i++)
    {
        if(i<cnt-1)
        {
            if(data[i]>=data[i+1])
            {
                ans=ans+data[i];
            }
            else
            {
                ans=ans-data[i];
            }
            /*printf("%d :%lld\n",i,ans);*/
        }
    }
    ans=ans+data[cnt-1];
    /*printf("%lld %lld\n",data[0],data[1]);*/
    printf("%lld",ans);
    return 0;
}
