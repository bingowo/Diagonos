#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char Hex[]="0123456789ABCDEF";
void getBin(int num1, int *r){
    for(int i=3; i>=0; i--){
        r[i] = num1%2;
        num1 /= 2;
    }
}
int main(){
    char s[10000];
    int num, r[4]; //r为余数
    scanf("%s", s);
    long long a=0, b=0, temp1, temp2;
    for(long long i=2; i<strlen(s); i++){
        num = strchr(Hex, s[i])-Hex;
        getBin(num, r);
        for(int j=0; j<4; j++){
            temp1 = a*-1-b+r[j]; //暂存改变后的a
            temp2 = a+b*-1; //暂存改变后的b
            a = temp1;
            b = temp2;
        }
    }
    if(a==0) {
        if(b==1) printf("i");
        if(b==-1) printf("-i");
        else printf("%di", b);
    }else if(b==0){
        printf("%d", a);
    }else{
        if(b==1) printf("%d+i", a);
        else if(b==-1) printf("%d-i", a);
        else if(b>1) printf("%d+%di", a, b);
        else printf("%d%di", a, b);
    }
    return 0;
}