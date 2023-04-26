#include<stdio.h>
int main()
{
    long long int n,m,s;
    scanf("%lld",&n);
    int cnt=0;

    while(1){cnt++;
        long long int tmp=n;
        int a[65]={0};
        int cnt=0;
        while(tmp)
        {
            a[cnt++]=tmp%10;
            tmp/=10;
        }
        m=0;
        for(int i=0;i<cnt;i++)
            m=m*10+a[i];
        s=m+n;
        tmp=s;
        int b[65]={0};
        cnt=0;
         while(tmp)
        {
            b[cnt++]=tmp%10;
            tmp/=10;
        }
        int flag=1;
        for(int i=0;i<cnt;i++)

        if(b[i]!=b[cnt-i-1]){flag=0;break;}
        if(flag==1)break;
        else n=s;
    }
    printf("%d %lld\n",cnt,s);

}
