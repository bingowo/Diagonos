#include<stdio.h>
int main(){
    char table[38] = "0123456789ABCDEFGHIJKLMNOPQRTSUVWXYZ";
    int T,flag = 0;
    int N,R;int j = 0;
    int ans[999][999];
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d%d",&N,&R);
        flag = 0;
        if (N < 0) flag = 1,N *= -1;
        do{
            ans[i][j++] = N % R;
            N /= R;
        }while(N);
        if (flag) printf("-");
        for (int k = j - 1;k > -1;k--){
            printf("%c",table[ans[i][k]]);
        }
        printf("\n");j = 0;
    }
    return 0;
}