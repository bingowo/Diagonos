#include<stdio.h>
int main(){
    int T,cnt = 0,res[11][32],temp = 0,n,j = 0;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        do{
            res[i][j++] = n % 2;
            n /= 2;
        }while(n);
        for(int k = j - 2;k > -1;k--){
            if(res[i][k] != res [i][k + 1]){
                cnt++;
                temp = (cnt > temp)?cnt:temp;
            }
            else cnt = 0;
        printf("case #%d:\n%d\n",i,temp);
        j = 0,cnt = 0;
    }
    return 0;
}