#include<stdio.h>
#include<stdlib.h>
#define N 100

typedef struct{
    int cnt,v[N];
}BigInt;

//大数据加法
BigInt add(BigInt a,BigInt b){
    BigInt R = {a.cnt > b.cnt ? a.cnt + 1 : b.cnt + 1,{0}};
    int carry = 0;
    int temp;
    int i;
    for(i = 0;i < R.cnt;i++){
        temp = carry + a.v[i] + b.v[i];
        carry = temp / 10;
        R.v[i] = temp % 10;
    }
    if(R.v[R.cnt] == 0)
        R.cnt--;
    return R;
}

//将int转换为BigInt
BigInt int2Big(int x){
    BigInt R = {0,{0}};
    int temp;
    do
    {
        temp = x % 10;
        R.v[R.cnt++] = temp;
        x /= 10;
    } while (x > 0);
    return R;
}

BigInt powadd(int n){
    BigInt R;
    if(n == 0){
        return int2Big(0);
    }
    if(n == 1 || n == 2){
        return int2Big(1);
    }
    return add(powadd(n - 1),powadd(n-2));
}


int main(){
    int n;
    scanf("%d",&n);
    BigInt R = powadd(n);
    for(int i = R.cnt - 1; i >= 0; i--){
        printf("%d",R.v[i]);
    }
    return 0;
}