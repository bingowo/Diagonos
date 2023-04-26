#include<stdio.h>
int main(){
    int T,cnt = 0,temp[11][32],n,j = 0;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        do{
            temp[i][j++] = n % 2;
            n /= 2;
        }while(n);
        for(int k = j - 2;k > -1;k--){
            if(temp[i][k] != temp [i][k + 1]) cnt++;
        printf("case #%d:\n%d",i,cnt);
        j = 0,cnt = 0;
    }
    return 0;
}