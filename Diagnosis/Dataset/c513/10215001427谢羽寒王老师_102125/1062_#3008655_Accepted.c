#include <stdio.h>
#include <string.h>


long long count(int n)
{
     long long a=1,b=2,c=4,d=8,t=0,i;
    for(i=5;i<=n;i++){
        t=a+b+c+d;
        a=b;
        b=c;
        c=d;
        d=t;


    }
return t;


}
int main()
{
    int T,n,i;
    long long r;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d",&n);
        if(n==0) r=0;
        if(n==1) r=1;
        if(n==2) r=2;
        if(n==3) r=4;
        if(n==4) r=8;
        if(n>4) r=count(n);

        printf("case #%d:\n",i);
        printf("%lld\n",r);

    }
    return 0;


}