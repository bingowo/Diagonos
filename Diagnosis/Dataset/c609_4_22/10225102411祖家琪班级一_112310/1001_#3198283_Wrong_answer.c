#include<stdio.h>
int main(){
    char table[38] = "0123456789ABCDEFGHIJKLMNOPQRTSUVWXYZ";
    int T,flag = 0;
    int N,R,j = 0;
    int ans[999][999];
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d%d",&N,&R);
        if (N < 0) flag = 1,N *= -1;
        do{
            N /= R;
            ans[i][j++] = N % R;
        }while(N);
        if (flag) printf("-");
        for (j;j > -1;j--){
            printf("%c",table[ans[i][j]]);
        }
        printf("\n");
    }
    return 0;
}