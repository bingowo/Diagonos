
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct data
{
    char A[3];
    int LL[10000];
    int sum;
    int flag;
    int cnt;
};

struct data2
{
    char A[3];
    char B[3];
    int cnt;
};

struct data convert(char s[])
{
    struct data R = {"0",{0},0,1,0};
    char *p = s;
    //找到逗号的位置 是指针p
    while(*p){
        if(*p == ',') break;
        p++;
    }
    char *p1 = s;
    while(*p1){
        p1++;
    } //p1指向字符串的末尾
    char *p0 = s;//p0指向字符串的开头
    //将开头部分的字符串复制到R.A
    strncpy(R.A,s,p-p0);
    //处理后面的数字
    p+=1;
    while(p != p1){
        R.LL[R.cnt++] = *p-'0';
        p++;
    }
    if(*p == '-'){
        R.flag = -1;
        p++;
    }
    double sum0 = 0;
    for(int j=0;j<R.cnt;j++){
        sum0 +=(double)R.LL[j] * pow(10.0,(R.cnt-j-1));
    }
    R.sum = (int)sum0;
    return R;
}

struct data2 convert2(char s[])
{
    struct data2 R = {"0","0",0};
    char *p = s;
    //找到逗号的位置 是指针p
    while(*p){
        if(*p == ',') break;
        p++;
    }
    char *p1 = s;
    while(*p1){
        p1++;
    } //p1指向字符串的末尾
    char *p0 = s;//p0指向字符串的开头
    //将开头部分的字符串复制到R.A
    strncpy(R.A,s,p-p0);
    p+=1;
    while(p != p1){
        R.B[R.cnt++] = *p;
        p++;
    }
    R.B[R.cnt] = '\0';
    return R;
}

int main()
{
    //指令和寄存器
    char s[100],A[3];
    int cnt = 0,cnt2 = 0,L[4];
    //先输入一个指令
    while(scanf("%s",s) != EOF){
    //先输入一组数据
    do{
        struct data R;
        struct data2 R2;
        if(strcmp(s,"IN") == 0){
            //如果是in,就输入一个字符串（寄存器+数字）
            scanf("%s",A);
            R = convert(A);
            //R.sum对应的是数字，R.A对应的是指令
            //根据输入的寄存器，放在相应的int数组的对应位置
            if(strcmp(R.A,"AX") == 0) cnt = 0;
            else if(strcmp(R.A,"BX") == 0) cnt = 1;
            else if(strcmp(R.A,"CX") == 0) cnt = 2;
            else if(strcmp(R.A,"DX") == 0) cnt = 3;
            //相应的位置对应的寄存器放好数字
            L[cnt] = R.sum*R.flag;
        }
        else if(strcmp(s,"MOV") == 0){
            //这种情况下，是两个寄存器进行赋值运算
            scanf("%s",A);
            R2 = convert2(A);
            if(strcmp(R2.A,"AX") == 0) cnt = 0;
            else if(strcmp(R2.A,"BX") == 0) cnt = 1;
            else if(strcmp(R2.A,"CX") == 0) cnt = 2;
            else if(strcmp(R2.A,"DX") == 0) cnt = 3;
            if(strcmp(R2.B,"AX") == 0) cnt2 = 0;
            else if(strcmp(R2.B,"BX") == 0) cnt2 = 1;
            else if(strcmp(R2.B,"CX") == 0) cnt2 = 2;
            else if(strcmp(R2.B,"DX") == 0) cnt2 = 3;
            L[cnt] = L[cnt2];
        }
        else if(strcmp(s,"ADD") == 0){
            //两个寄存器的加法运算
            scanf("%s",A);
            R2 = convert2(A);
            if(strcmp(R2.A,"AX") == 0) cnt = 0;
            else if(strcmp(R2.A,"BX") == 0) cnt = 1;
            else if(strcmp(R2.A,"CX") == 0) cnt = 2;
            else if(strcmp(R2.A,"DX") == 0) cnt = 3;
            if(strcmp(R2.B,"AX") == 0) cnt2 = 0;
            else if(strcmp(R2.B,"BX") == 0) cnt2 = 1;
            else if(strcmp(R2.B,"CX") == 0) cnt2 = 2;
            else if(strcmp(R2.B,"DX") == 0) cnt2 = 3;
            L[cnt] = L[cnt]+L[cnt2];
        }
        else if(strcmp(s,"SUB") == 0){
            //两个寄存器的减法运算
            scanf("%s",A);
            R2 = convert2(A);
            if(strcmp(R2.A,"AX") == 0) cnt = 0;
            else if(strcmp(R2.A,"BX") == 0) cnt = 1;
            else if(strcmp(R2.A,"CX") == 0) cnt = 2;
            else if(strcmp(R2.A,"DX") == 0) cnt = 3;
            if(strcmp(R2.B,"AX") == 0) cnt2 = 0;
            else if(strcmp(R2.B,"BX") == 0) cnt2 = 1;
            else if(strcmp(R2.B,"CX") == 0) cnt2 = 2;
            else if(strcmp(R2.B,"DX") == 0) cnt2 = 3;
            L[cnt] = L[cnt]-L[cnt2];
        }
        else if(strcmp(s,"MUL") == 0){
            scanf("%s",A);
            R2 = convert2(A);
            if(strcmp(R2.A,"AX") == 0) cnt = 0;
            else if(strcmp(R2.A,"BX") == 0) cnt = 1;
            else if(strcmp(R2.A,"CX") == 0) cnt = 2;
            else if(strcmp(R2.A,"DX") == 0) cnt = 3;
            if(strcmp(R2.B,"AX") == 0) cnt2 = 0;
            else if(strcmp(R2.B,"BX") == 0) cnt2 = 1;
            else if(strcmp(R2.B,"CX") == 0) cnt2 = 2;
            else if(strcmp(R2.B,"DX") == 0) cnt2 = 3;
            L[cnt] = L[cnt]*L[cnt2];
        }
        else if(strcmp(s,"DIV") == 0){
            scanf("%s",A);
            R2 = convert2(A);
            if(strcmp(R2.A,"AX") == 0) cnt = 0;
            else if(strcmp(R2.A,"BX") == 0) cnt = 1;
            else if(strcmp(R2.A,"CX") == 0) cnt = 2;
            else if(strcmp(R2.A,"DX") == 0) cnt = 3;
            if(strcmp(R2.B,"AX") == 0) cnt2 = 0;
            else if(strcmp(R2.B,"BX") == 0) cnt2 = 1;
            else if(strcmp(R2.B,"CX") == 0) cnt2 = 2;
            else if(strcmp(R2.B,"DX") == 0) cnt2 = 3;
            L[cnt] = L[cnt]/L[cnt2];
        }
        scanf("%s",s);
    }while(strcmp(s,"OUT") != 0);
    //如果输入的指令不是out，那么就继续输入
    //如果是out就进行输出
    if(strcmp(s,"OUT") == 0){
        scanf("%s",A);
        if(strcmp(A,"AX") == 0) cnt = 0;
        else if(strcmp(A,"BX") == 0) cnt = 1;
        else if(strcmp(A,"CX") == 0) cnt = 2;
        else if(strcmp(A,"DX") == 0) cnt = 3;
        printf("%d\n",L[cnt]);
    }
    }
}
