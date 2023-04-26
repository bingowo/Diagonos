#include<stdio.h>
int main(){
    char table[38] = "0123456789ABCDEFGHIJKLMNOPQRTSUVWXYZ";
    int T,m = 0,n = 0,flag = 0;
    int N[999],R[999];
    int ans[999][999];
    scanf("%d\n",&T);
    do{
        scanf("%d ,%d",&N[m++],&R[n++]);
    }while (getchar() != '\n');
    for(int i = 0;i < T + 1;i++){
        int k = 0,j = 0;
        if (N[i] == 0) ans[i][j] = 0,k++;
        if (N[i] < 0) flag = 1,N[i] *= -1;
        while (N[i] > 0){
            ans[i][j++] = table[N[i] % R[i]];
            N[i] /= R[i];
            k++;
        }
        for (int u = k;u > -1;0;u--){
            if (flag) printf("-");
            printf("%c",table[ans[i][u]]);
        }
        printf("\n");
        j = 0;k = 0;
    }
    return 0;
}