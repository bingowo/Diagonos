#include <stdio.h>

int main() {
    long long x,y;
    scanf("%lld%lld",&x,&y);
    x=(x<0)?(-1*x):x;
    y=(y<0)?(-1*y):y;
    long long z;
    z=x+y;
    if(z==0)
        printf("0\n");
    else if(z %2==0)
        printf("-1\n");
    else
    {
        z+=1;
        for(int k=1;k<30;k++) {
            if ((1LL << (k - 1)) < z && z <= (1LL << k)) {
                printf("%d\n", k);
                break;
            }
        }
    }
    return 0;
}
