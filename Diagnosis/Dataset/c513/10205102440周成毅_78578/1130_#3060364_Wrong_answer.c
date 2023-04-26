#include <stdio.h>
#include <string.h>

int main() {
    long long piu[64][64];
    for(int i=0;i<64;i++)
        for(int j=0;j<64;j++)
            piu[i][j]=1;
    for(int i=1;i<=63;i++)
        for(int j=1;j<=63;j++)
            piu[i][j]=i*piu[i][j-1];
    int num;
    scanf("%d",&num);
    while(num--){
        long long tt;
        int flag=1;
        int print=1;
        scanf("%lld",&tt);
        if(tt<4){
            printf("%lld is powerless.\n",tt);
            continue;
        }
        for(int i=64;i>=1;i--){
            for(int j=1;j<=16;j++){
                if(tt==piu[i][j]){
                    if(flag) {
                        printf("%lld", tt);
                        flag = 0;
                        print=0;
                    }
                    printf("=%d^%d",i,j);
                }
            }
        }
        if(print)
            printf("%lld is powerless.\n",tt);
        else
            printf("\n");
    }

    return 0;
}
