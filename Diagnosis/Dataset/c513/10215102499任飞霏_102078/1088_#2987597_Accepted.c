#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//这个方法有些取巧

long long gcd(long long a,long long b)
{
    long long t=a%b;
    while(t>0){
        a=b;
        b=t;
        t=a%b;
    }
    return b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        long long m,n;
        scanf("%lld%lld",&m,&n);
        long long res1=m,res2=n;
        if(n==0)printf("1\n");
        else{
            while(n>1){
                int t=gcd(res1,res2);
                res1=res1*(m-1)/t;
                res2=res2*(n-1)/t;
                m--;n--;
            }
        printf("%lld\n",res1/res2);
        }

    }
    return 0;
}
