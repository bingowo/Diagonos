//1052 高精度+低精度 高精度*低精度
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int prime[] = {1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79, 83, 89, 97};
int ans[100001], len=1, num[26];
void multiply(int x){  
    int pos=0, temp=0;
    while(pos<len){
        ans[pos] = ans[pos]*x+temp;
        temp = ans[pos]/10;
        ans[pos++] %= 10;
    }
    while(temp!=0){
        ans[len++] =temp%10;
        temp /= 10;
    }
}

void add(int n){
    int pos=0, temp=n;
    while(pos<len){
        ans[pos] += temp;
        temp = ans[pos]/10;
        ans[pos++] %= 10;
        if(temp==0) break; 
    }
    while(temp!=0){
        ans[len++] = temp%10;
        temp /= 10;
    }
}

int main(){
    int count=0;
    char c = getchar();
    while(c==','||(c>='0'&&c<='9')){//读
        if(c!=',')
            num[count] = num[count]*10+(char)c-48;
        else count++;
        c = getchar();
    }
    count++;
    for(int i=0; i<count; i++){//先加后乘比前一位多的倍数
        add(num[i]);
        multiply(prime[count-i-1]);
    }
    for(int i=0; i<len; i++) printf("%d", ans[len-1-i]);
    return 0;
}