#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* bin(int a,char* b){
    int num = 0,count = 0,rem;
    char *p = NULL;
    while(a!= 0){
        rem = a % 2;
        a = a / 2;
        b[count++] = rem + '0';
    }
    while(strlen(b) != 10){
        b[count++] = '0';
    }
    p = b;
    return p;
}
int main(){
    char digit[500],*p = NULL;
    int num = 0,length;
    int flag;
    char a[11] = {'\0'};
    scanf("%s",digit);
    length = strlen(digit);
    flag = length % 3;
    printf("0001");
    p = bin(length,a);
    for(int i = strlen(p)-1;i >=0 ;i--)
        printf("%c",*(p+i));
    
    for(int i = 0;i < length ;i++){
        num = num * 10 + digit[i] - '0';
        if((i+1)%3 == 0 || i == length-1){
            char qr[11] = {'\0'};
            p = bin(num,qr);
            if(i != length -1){
                for(int j = strlen(p)-1;j >= 0;j--)
                        printf("%c",*(p+j));
            }
            else if(flag == 2){
                    for(int j = 6;j >= 0;j--)
                        printf("%c",*(p+j));
                }
                else if(flag == 1){
                        for(int j = 3;j >= 0;j--)
                            printf("%c",*(p+j));
                }
                else{ 
                    for(int j = strlen(p)-1;j >= 0;j--)
                        printf("%c",*(p+j));
                }
            num  = 0;
        }
    }
}
