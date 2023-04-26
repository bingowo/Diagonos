#include <stdio.h>
#include <string.h>
int main() {
    char l[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[200] ={0};
        int a[200] ={0};
        int b[500] = {0};
        int ret[100] = {0};
        scanf("%s",s);
        int q=0;
        for(;q< strlen(s);q++){
            a[q] = s[q];
            for(int k=7;k>=0;k--){
                b[q*8+7-k] = (a[q]>>k)&1;
            }
        }
        printf("case #%d:\n",i);
        int p=0;
        int max =8*q/6;
        if((8*q)%6 != 0){
            max++;
        }
        for(;p<max;p++){
            for(int m=0;m<6;m++){
                ret[p] = b[p*6+m]+ret[p]*2;
            }
            printf("%c",l[ret[p]]);
        }
        if(p%4==1){
            printf("===");
        }if(p%4==2){
            printf("==");
        }if(p%4==3) {
            printf("=");
        }
        printf("\n");
    }
    return 0;
}
