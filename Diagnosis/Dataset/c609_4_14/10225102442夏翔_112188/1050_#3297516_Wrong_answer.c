//1050 高精度+高精度
#include <stdio.h>
#include <string.h>
int A1[501], len1, A2[501], len2, B1[501], len3, B2[501], len4;

int max(int a, int b){
    return (a>b)? a: b;
}

void read(){
    char c;
    c = getchar();
    while(c!='.' && c!=' '){
        A1[len1++] = (int)c-48;
        c = getchar();
    }
    if(len1==0) len1++;
    if(c!=' '){ //防止无小数部分（无小数点情况）
        c = getchar();
        while(c!=' '){
            A2[len2++] = (int)c-48;
            c = getchar();
        }
    }
    c = getchar();
    while(c!='.' && c!=' '){
        B1[len3++] = (int)c-48;
        c = getchar();
    }
    if(len3==0) len3++;
    if(c!=' '){  
        c = getchar();
        while(c!=' '){
            B2[len4++] = (int)c-48;
            c = getchar();
        }
    }
}
void transfer(){ //把整数部分弄成高位在后
    int temp;
    for(int i=0; i<=len1/2; i++){
        temp = A1[i];
        A1[i] = A1[len1-1-i];
        A1[len1-1-i] = temp;
    }
    for(int i=0; i<=len3/2; i++){
        temp = B1[i];
        B1[i] = B1[len1-1-i];
        B1[len1-1-i] = temp;
    }
}

void roundOff(int N){ //N位以后四舍五入
    if(A2[N]<5) return;
    else{
        int temp = 1, pos = N-1;
        while(pos!=-1 && temp!=0){ //小数部分
            A2[pos] += temp;
            temp = A2[pos]/10;
            A2[pos--] %= 10;
        }
        pos = 0;
        while(temp!=0){ //整数部分
            A1[pos] += temp;
            temp = A1[pos]/10;
            A1[pos++] %= 10;
        }
        if(pos>len1) len1 = pos;
    }
}

void add(){ //两浮点数相加
    int temp = 0, len=max(len2, len4), pos=0;
    while(len!=0){  //小数部分高精度相加
        A2[len-1] += B2[len-1] + temp;
        temp = A2[len-1]/10;
        A2[len-1] %= 10;
        len--;
    }
    len = max(len1, len3);
    while(pos<len){ //整数部分高精度相加
        A1[pos] += B1[pos]+temp;
        temp = A1[pos]/10;
        A1[pos++] %= 10;
    }
    while(temp!=0){
        A1[pos++] = temp%10;
        temp /= 10;
    }
    if(pos>len1) len1 = pos;
}

int main(){
    int N;
    read();
    scanf("%d", &N);
    transfer(); //整数部分最好从低位到高位
    add();
    roundOff(N); //四舍五入
    for(int i=0; i<len1; i++) printf("%d", A1[len1-i-1]);
    printf(".");
    for(int i=0; i<N; i++) printf("%d", A2[i]);
    return 0;
}