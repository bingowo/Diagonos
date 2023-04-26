#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int a=0,b=0,k=0,n=0,m=0;
        scanf("%d %d %d %d %d",&a,&b,&k,&n,&m);
        long long int zi=1,mu=1,x=0,y=0,ans=0;
        int m1=m>n? n:m;
        for(int j=0;j<m1;j++){
            zi*=(k-j);
            mu*=(j+1);
            if(zi%mu==0) {zi/=mu;mu=1;}
        }
        x=pow(a,n);
        y=pow(b,m);
        ans=(zi/mu)*x*y;
        printf("case #%d:\n",t);
        printf("%lld\n",ans);
    }
    return 0;
}
