#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A;
    scanf("%d",&A);
    int i=1;
    for(i=2;i<10000;i++)
    {
        long long res=i*A;
        long long tmp=res;
        int flag=1;
        while (tmp>0)
        {
            if(tmp%10!=1 && tmp%10!=0) {flag=0;break;}
            //else tmp/=10;
        }
        if(flag==1)
        {
            printf("%lld",res);
            break;
        }
    }
    if(i==10000) printf("-1");
    return 0;
}