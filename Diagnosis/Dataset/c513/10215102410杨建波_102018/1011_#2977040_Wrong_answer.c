#include<stdio.h>

int main(){
    int n,a = -1, b = 1, bin[100],i = 0,count = 0;
    int sum1 = 0,sum2 = 0;
    scanf("0x%X",&n);
    while(n != 0){
        bin[i++] = n % 2;
        n = n / 2;
    }
    i--;
    for(i;i >= 0;i--){
        int t = sum1;
        if((count++)%2 == 1)
            sum1 = sum1*a + sum2*b + bin[i];
        else{
            sum1 = sum1*a - sum2*b + bin[i];
            count++;
        }
        sum2 = t*b + a*sum2;
    }
    printf("%d %d",sum1,sum2);
}
