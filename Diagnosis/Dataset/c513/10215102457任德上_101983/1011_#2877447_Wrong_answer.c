#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void binary(long long int a,char *s){
    long long int i=1;
    for(int m=64;m>0;m--,s++,a=a>>1){*s='0'+(int)(a&i);}
    *s=0;
}
int main(){
    long long int i,a,b,a1=0,b1=0;
    char s[65];
    scanf("%x",&i);
    binary(i,s);
    for(int m=64;m>0;m--){
        a=-a1-b1+s[64-m]-'0';
        b=a1-b1;
        a1=a;
        b1=b;
        printf("%d+%di\n",a,b);
    }
    printf("%d+%di",a,b);
    return 0;
}

