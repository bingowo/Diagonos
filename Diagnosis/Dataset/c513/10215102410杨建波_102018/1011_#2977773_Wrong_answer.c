#include<stdio.h>
#include<string.h>

int main(){
    long long a = -1, b = 1,sum1 = 0,sum2 = 0;
    char n[100] = {'\0'};
    scanf("0x%s",n);
    for(int i = 0;i < strlen(n);i++){
        int j = 0;
        char  bin[4] = {'0','0','0','0'};
        if('0' <= n[i]&&n[i] <= '9'){
            int t = n[i] - '0' ;
            while(t != 0){
            bin[j++] = t % 2 +'0';
            t = t / 2;
            }   
        }
        else {
            int t = n[i] -'A'+ 10;
            while(t != 0){
            bin[j++] = t % 2 + '0';
            t = t / 2;
            }  
        }
        for(int i = 3;i >= 0;i--){
            long long int t = sum1;
            sum1 = sum1*a - sum2*b + (bin[i] -'0');
            sum2 = t*b + a*sum2;
        }
    }
    
    if(sum1 == 0){
         if(sum2 == 0)printf("0");
    }
    else printf("%lld",sum1);
    if(sum2 == 0);
    else if(sum2 == 1&&sum1 != 0)printf("i");
    else if(sum2 == 1)printf("+i");
    else if(sum2 == -1)printf("-i");
    else if(sum2 > 0)
        printf("+%lldi",sum2);
    else
        printf("%lldi",sum2);
}
