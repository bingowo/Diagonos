//思路 除得整数位
//后面开始小数点后的运算
#include <stdio.h>
#include <stdlib.h>

void solve(int n,int m){
    int rmdr[10000]={0};
    int j = 1;
    int t = n/m;
    rmdr[n%m] = j++;
    n %=m;
    printf("%d.",t);
    while(n%m != 0){
        n*=10;
        int k = n/m;
        printf("%d",k);
        n%=m;
        if(rmdr[n]){
            printf("\n");
            printf("%d-%d",rmdr[n],j-1);
            printf("\n");
            return;
        }else{
            rmdr[n] = j++;
        }

    }
    printf("\n");


}

int main(){
    int round = 0;
    scanf("%d",&round);
    for(int i = 0; i < round;i++){
        int n,m;
        scanf("%d %d",&n,&m);//n是除数 m是被除数
        printf("case #%d:",i);
        printf("\n");
        solve(n,m);

    }
}