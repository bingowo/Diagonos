#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x == 1 || x == 2){
        printf("%d",a);
        return 0;
    }else if(x == 3){
        printf("%d",2*a);
        return 0;
    }else if(x == (n - 1)){
        printf("%d",m);
        return 0;
    }
    int t = (m - (n - 3) * a) / (feibo(n - 2) - 1);
    int ans = (feibo(x - 2) + 1) * a + (feibo(x - 1) - 1) * t;
    printf("%d",ans);
    return 0;
}

int feibo(int t){
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

