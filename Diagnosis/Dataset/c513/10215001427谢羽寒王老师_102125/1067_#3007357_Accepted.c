#include <stdio.h>
#include <string.h>

long long count(long long n)
{
    long long int a=0,b=1,c=1,t=0,i;
    for(i=3;i<=n;i++){
        t=a+b+c;
        a=b;
        b=c;
        c=t;


    }
return t;


}
int main()
{
    int T,j;

    scanf("%d",&T);
    for(j=0;j<T;j++){
        long long int n,result;

        scanf("%lld",&n);
        if(n==0) result=0;
        if(n==1) result=1;
        if(n==2) result=1;
        if(n>2) result=count(n);



        printf("case #%d:\n",j);
        printf("%lld\n",result);
    }



}

