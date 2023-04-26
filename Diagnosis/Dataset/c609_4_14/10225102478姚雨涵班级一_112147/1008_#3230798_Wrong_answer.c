#include <stdio.h>
char table[] = "0123456789abcdef";
int dou(double a){
    int* p = (int*) &a;
    char ans[16];
    for(int i = 0;i<16;i++){
        int temp = 0;
        for(int k = 0;k<4;k++){

            if(*p&1){
                temp = temp * 2 +1;
            }
            else
                temp *= 2;
            *p>>1;
        }
        ans[i] = table[temp];
    }
    for(int i = 15;i >= 0;i--){
        printf("%c",ans[i]);
        if(i<15 && i%2)
            printf(" ");
    }
    printf("\n");
}
int in(int a){
    unsigned int t = a;
    char ans[8];
    for(int i = 0;i<8;i++){
        int temp = 0;
        for(int k = 0;k<4;k++){

            if(t&1){
                temp = temp * 2 +1;
            }
            else
                temp *= 2;
            t>>1;
        }
        ans[i] = table[temp];
    }
    for(int i = 7;i >= 0;i--){
        printf("%c",ans[i]);
        if(i<15 && i%2)
            printf(" ");
    }
    printf("\n");
}
int main(){
    double n[100001];
    for(int i = 0;scanf("%lld",&n[i]);i++){
        if(n[i] - (int)n[i] != 0||n[i] == 0){
            dou(n[i]);
        }
        else{
            int b = n[i];
            in(b);
        }
    }
    return 0;
}
