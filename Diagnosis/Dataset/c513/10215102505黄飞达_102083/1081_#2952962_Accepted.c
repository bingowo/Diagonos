#include<stdio.h>

int fang(int a, int b, int res[]){
    int index=0, up=0;
    for (int i=0; i<b; i++){
        up=0;
        for (int j=0; j<=index; j++){
            res[j] = res[j]*a + up;
            up = res[j]/10;
            res[j] %= 10;
        }
        while(up){
            res[++index] += up%10;
            up /= 10;
        }
    }
    for (int i=index; i>=0; i--){
        if (res[i]!=0) break;
        else index--;
    }
    return index;
}

int main(){
    int T;
    scanf("%d ",&T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        int a, b;
        scanf("%d %d", &a, &b);
        int res[100000]={1};
        int index=fang(a, b, res);
        for (int i=index; i>=0; i--) printf("%d", res[i]);
        printf("\n");
    }
    return 0;
}