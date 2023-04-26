#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    int idx=0;
    while(t--){
        char oct[55],dec[155];
        scanf("%s",oct);
        int numbers=0;//记录当前十进制小数位数
        int len=strlen(oct)-1;
        long double digit;
        for(;len!=1;--len){//从八进制小数的最后一位开始循环
                digit=oct[len]-'0';//digit初始化为八进制当前数码，后续作余数
                int j=0;
                long long int temp;
                do{ //进入高精度除法，temp存储被除数；
                    if(j<numbers)temp=digit*10+dec[j]-'0';
                    else temp=digit*10;
                    dec[j++]=temp/8+'0';
                    digit=temp%8;
                }while(digit!=0||j<numbers);
                numbers=j;
        }
        dec[numbers]='\0';
        printf("0.%s",dec);
    }
}
