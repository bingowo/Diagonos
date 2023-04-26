#include <stdio.h>
#include <stdlib.h>

long long int feibo(long long int t);

int main()
{
    long long int a,n,m,x;
    scanf("%lld %lld %lld %lld",&a,&n,&m,&x);
    if(x == 1 || x == 2){
        printf("%lld",a);
        return 0;
    }else if(x == 3){
        printf("%lld",2*a);
        return 0;
    }else if(x == (n - 1)){
        printf("%lld",m);
        return 0;
    }
    long long int t = (m - (feibo(n-3)+1)*a)/(feibo(n-2)-1);
    long long int ans = (feibo(x - 2) + 1) * a + (feibo(x - 1) - 1) * t;
    printf("%lld",ans);
    return 0;
}

long long int feibo(long long int t){
    if(t == 0){
        return 0;
    }else if(t == 1){
        return 1;
    }else if (t == 2){
        return 1;
    }else{
        return feibo(t -1) + feibo(t - 2);
    }
}

