#include<stdio.h>
#include<stdlib.h>
int main()
{
    int input,T,n,m;
    char *dic = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&T);

    for(int i = 0,input = 0;i < T;i++){
        scanf("%d%d",&input,&n);
        int mi = 1;
        if(input < 0){
            input = abs(input);
            mi = 0;
        }
        char output[32] = {0};
        for(m = 0;input != 0;m++){
            output[m] = *(dic+input%n);
            input /= n;
        }
        if(m == 0){
            printf("0\n");
            continue;
        }
        else{
            if(mi == 0) putchar('-');
            for(m--;m >= 0;m--){
                printf("%c",output[m]);
            }
            putchar('\n');
            continue;
        }
    }
    return 0;
}