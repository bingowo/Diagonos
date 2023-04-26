#include<stdio.h>
int main(){
    int T,cnt,res[11][32],temp = 0,n,j = 0,cntres;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        scanf("%d",&n);
        do{
            res[i][j++] = n % 2;
            n /= 2;
        }while(n);
        cnt = (res[i][j - 1] == 1)?1:0;
        for(int k = j - 2;k > -1;k--){
            cntres = cnt;
            if(res[i][k] != res [i][k + 1] && res[i][k] == 1){
                cnt += 2;
                temp = (cnt > temp)?cnt:temp;
            }
            else cnt = cntres;
        }
        printf("case #%d:\n%d\n",i,temp);
        j = 0,cnt = 0;
    }
    return 0;
}