#include<stdio.h>

int main(){
    int T, a, b;
    scanf("%d",&T);
    for(T;T > 0 ;T--){
        int count = 0;
        scanf("%d %d",&a,&b);
        int c = a ^ b;
        for(int i = 0;i < 8*sizeof(int);i++){
            if((c>>i)&1 == 1)count++;
        }
        printf("%d\n",count);
    }
}