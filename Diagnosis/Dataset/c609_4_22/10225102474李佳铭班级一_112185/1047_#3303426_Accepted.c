#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 102

//存大数据
typedef struct{
    int cnt,v[N];
}BigInt;

//a * BigInt
void chengfa(BigInt* R,int a){
    //进位
    int carry = 0;
    int i = 0;
    int temp;
    do{
        temp = R->v[i]*a + carry;
        R->v[i] = temp % 10;
        carry = temp / 10;
        if(i == R->cnt){
            if(carry != 0){
                R->cnt++;
            }
        }
        i++;
    }while(i <= R->cnt);

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        int a,n;
        BigInt R = {0,{1}};
        scanf("%d %d",&a,&n);
        if(n == 0){
            printf("case #%d:\n%d",i,1);
            if(i != T - 1)
                printf("\n");
            continue;
        }
        for(int j = 0; j < n; j++){
            chengfa(&R,a);
        }
        printf("case #%d:\n",i);
        for(int j = R.cnt;j >= 0;j--){
            printf("%d",R.v[j]);
        }
        if(i != T - 1)
                printf("\n");
    }
}