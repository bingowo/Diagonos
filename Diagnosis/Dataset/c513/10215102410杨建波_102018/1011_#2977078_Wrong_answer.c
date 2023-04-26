#include<stdio.h>

int main(){
    long long int a = -1, b = 1,sum1 = 0,sum2 = 0,n, bin[100],i = 0,count = 0;
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
    if(sum2 == 0)printf("%lld",sum1);
    else if(sum2 > 0)
        printf("%lld+%lldi",sum1,sum2);
    else if(sum2 == 1)
        printf("%lld+i",sum1,sum2);
    else if(sum1 == 0)
        printf("%lldi",sum2);
    else if(sum2 == 0&&sum1 == 0)
        printf("0");
    else 
        printf("%lld%lldi",sum1,sum2);
}
