#include<stdio.h>
int main(){
    int T,cnt,res[11][32],temp = 0,n,j = 0;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        do{
            res[i][j++] = n % 2;
            n /= 2;
        }while(n);
        cnt = (res[i][j - 1] == 1)?1:0;
        for(int k = j - 2;k > -1;k--){
            if(res[i][k] != res [i][k + 1] && res[i][k] == 1){
                cnt += 2;
                temp = (cnt > temp)?cnt:temp;
            }
            else if(k == 0 && res[i][k] != res [i][k + 1]){
                cnt++;
                temp = (cnt > temp)?cnt:temp;
            }
            else if (res[i][k] != res [i][k + 1])cnt += (res[i][k] == 1)?1:0;
            else if (res[i][k] == 1) temp = cnt;
        }
        printf("case #%d:\n%d\n",i,temp);
        j = 0,cnt = 0;
    }
    return 0;
}
