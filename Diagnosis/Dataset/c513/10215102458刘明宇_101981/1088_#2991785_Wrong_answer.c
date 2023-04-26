#include <stdio.h>
#include <stdlib.h>


int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        int n = 1,m = 1;
        unsigned long long p = 1;
        int small,large;
        scanf("%d %d",&m,&n);
        if(m-n>n){small = n;large = m-n;}
        else{
            small = m-n;
            large = n;
        }
        for(int i = m;i>large;i--){
            if(i == 2*small){
                p = p*2;
                small--;
            }
            else p = p*i;
        }
        while(small >1){
            p = p/small;
            small--;
        }
        printf("case #%d:\n",cnt);
        printf("%lld",p);
        printf("\n");
    }
}
