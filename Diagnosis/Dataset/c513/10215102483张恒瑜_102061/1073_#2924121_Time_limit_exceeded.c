#include<stdio.h>
#include<string.h>

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long cnt=0;
    while(a<=b)
    {
        cnt++;
        char tmp[20]={'\0'};
        int flag=0;
        sprintf(tmp,"%lld",a);
        for(int j=strlen(tmp);j>=0;j--)
        {
            if(tmp[j]=='9')
            {
                cnt--;
                flag=1;
                long long weight=1;
                for(int p=j;p<strlen(tmp)-1;p++) weight*=10;
                a+=weight-1;
                break;
            }
        }
        if(flag==0)
            if(a%9==0)
                cnt--;
        a++;
    }
    printf("%lld",cnt);
}
