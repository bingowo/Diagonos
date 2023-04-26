#include<stdio.h>
int main(){
    int T,cnt = 1,res[11][32],temp = 1,n,j = 0;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        do{
            res[i][j++] = n % 2;
            n /= 2;
        }while(n);
        for(int k = j - 2;k > -1;k--){
            if(res[i][k] == res[i][k + 1]){
                cnt = 1;
            }
            else if(res[i][k] != res[i][k + 1]){
                cnt++;
                temp = (cnt > temp)?cnt:temp;
            }
        }
        printf("case #%d:\n%d\n",i,temp);
        j = 0,cnt = 0;temp = 0;
    }
    return 0;
}