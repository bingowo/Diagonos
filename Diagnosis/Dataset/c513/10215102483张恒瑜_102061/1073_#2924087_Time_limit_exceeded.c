#include<stdio.h>
#include<string.h>

int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long cnt=b-a+1;
    for(long long i=a;i<=b;i++)
    {
        if(i%9!=0)
        {
            char tmp[20]={'\0'};
            sprintf(tmp,"%lld",i);
            for(int j=0;j<strlen(tmp);j++)
            {
                if(tmp[j]=='9')
                {
                    cnt--;
                    break;
                }
            }
        }
        else cnt--;
    }
    printf("%lld",cnt);
}
