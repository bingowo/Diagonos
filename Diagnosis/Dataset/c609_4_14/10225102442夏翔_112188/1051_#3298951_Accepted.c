//1051 高精度-高精度
#include <stdio.h>
#include <string.h>
int A1[501], len1, A2[501], len2, B1[501], len3, B2[501], len4;

int max(int a, int b){
    return (a>b)? a: b;
}

void read(){
    char c;
    int flag=0;
    c = getchar();
    while(c!='.' && c!=' '){
        if(flag==0 && c=='0'){  //前导0.。。
            c = getchar();
            continue;
        }
        A1[len1++] = (int)c-48;
        flag = 1;
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
    flag = 0;
    while(c!='.' && c!=' '){
        if(flag==0 && c=='0'){
            c = getchar();
            continue;
        }
        B1[len3++] = (int)c-48;
        flag = 1;
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
    for(int i=0; i<len1/2; i++){
        temp = A1[i];
        A1[i] = A1[len1-1-i];
        A1[len1-1-i] = temp;
    }
    for(int i=0; i<len3/2; i++){
        temp = B1[i];
        B1[i] = B1[len3-1-i];
        B1[len3-1-i] = temp;
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

int compare(){ //A大输出1， B大输出-1；
    if(len1>len3) return 1;
    else if(len1<len3) return -1;
    for(int i=0; i<len1; i++){
        if(A1[len1-i-1]>B1[len1-i-1]) return 1;
        else if(A1[len1-i-1]<B1[len1-i-1]) return -1;
    }
    int len=max(len2, len4);
    for(int i=0; i<len; i++){
        if(A2[i]>B2[i]) return 1;
        else if(A2[i]<B2[i]) return -1;
    }
    return 0; //相同
}

void swap(){ //交换A、B
    int temp, len;
    len = max(len1, len3);
    while(len--){
        temp = A1[len];
        A1[len] = B1[len];
        B1[len] = temp;
    }
    temp = len1; len1 = len3; len3 = temp;
    len = max(len2, len4);
    while(len--){
        temp = A2[len];
        A2[len] = B2[len];
        B2[len] = temp;
    }
    temp = len2; len2 = len4; len4 = temp;
}

void minus(){ //高精度-高精度（确定前大于后）
    int len=max(len2, len4), temp=0;
    while(len!=0){ //小数部分
        A2[len-1] -= B2[len-1]+temp;
        if(A2[len-1]<0){
            temp = 1;
            A2[len-1] += 10;
        }else temp = 0;
        len--;
    }
    for(int i=0; i<len1; i++){//整数部分
        A1[i] -= B1[i]+temp;
        if(A1[i]<0){
            temp = 1;
            A1[i] += 10;
        }else temp = 0;
    }
    while(A1[len1-1]==0 && len1>=1) len1--;//去除前导0
    if(len1==0) len1 = 1; //至少得有1吧
}

int main(){
    int N;
    read();
    scanf("%d", &N);
    transfer(); //整数部分最好从低位到高位
    int res=compare();
    if(res==0){ //相同直接输出0
        len1 = 1;//只有一位0
        memset(A1, 0, sizeof(A1));
        memset(A2, 0, sizeof(A2));
    }else{
        if(res==-1){
            swap(); //交换AB
            printf("-");
        }
        minus();
        roundOff(N); //四舍五入
    }
    for(int i=0; i<len1; i++) printf("%d", A1[len1-i-1]);
    printf(".");
    for(int i=0; i<N; i++) printf("%d", A2[i]);
    return 0;
}