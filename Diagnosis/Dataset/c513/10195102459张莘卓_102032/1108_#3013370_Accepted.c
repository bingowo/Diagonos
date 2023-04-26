#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n, m, flag[100]={0}, i=0;
        scanf("%d %d",&n, &m);
        printf("case #%d:\n0.",j);
        do{
            if(flag[n]){
                printf("\n%d-%d",flag[n],i);
                break;
            }else flag[n] = ++i;
            n *= 10;
            printf("%d",n/m);
            n %= m;
        }while(n);
        printf("\n");
    }
    return 0;
}
