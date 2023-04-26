#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    long long a, b;
    scanf("%lld %lld", &a, &b);
    int *integer, *decimal, num1=0, num2=0, temp;
    long long x1, x2;
    x1 = a/b;
    x2 = a%b;
    integer = (int*)calloc(65,sizeof(int));
    decimal = (int*)calloc(65,sizeof(int));
    while(x1!=0){  //求整数部分
        integer[num1++] = x1%3;
        x1 /= 3;
    }
    while(x2!=0){  //求小数部分
        decimal[num2++] = x2%3;
        x2 /= 3;
    }
    temp = 0;
    for(int i=0; i<num2; i++){  //小数部分逐位+1
        decimal[i] += 1+temp;
        if(decimal[i]>=3){
            temp = decimal[i]/3;
            decimal[i] = decimal[i]%3;
        }else temp = 0;
    }
    for(int i=0; i<num1; i++){  //整数部分逐位+1
        integer[i] += 1+temp;
        if(integer[i]>=3){
            temp = integer[i]/3;
            integer[i] = integer[i]%3;
        }else temp = 0;
    }
    while(temp!=0){  //整数部分逐位+1
        integer[num1++] = temp%3+1;
        temp = integer[num1]/3;
    }
    for(int i=0; i<num1; i++) integer[i]--;  
    for(int i=0; i<num2; i++) decimal[i]--;
    int ret=1; //标记是否是开头的0
    for(int i=0; i<num1; i++){
        if(integer[num1-i-1]==0&&ret==1) continue; //跳过开头的0
        if(integer[num1-i-1]==-1)printf("%d", 2);
        else printf("%d", integer[num1-i-1]);
        ret = 0; //遇到0不用跳
    }    
    int pos=0;      
    while(decimal[pos]==0&&pos<num2) pos++; //去掉小数末尾的0
    if(pos<num2) printf("%c", '.'); //仍有小数才需要输出
    for(int i=0; i<num2-pos; i++){
        if(decimal[num2-i-1]==-1) printf("%d", 2);
        else printf("%d", decimal[num2-i-1]);
    }
    free(decimal);
    free(integer);
    return 0;
} 