#include <stdio.h>
#include <string.h>
#define L 500

void input(int a[]){   //输入一个浮点数
    char s[L+1];
    scanf("%s",s);
    int i=0,j,k;
    while (s[i] && s[i]!='.') i++; //定位小数点，i即为小数点下标
    for(j=i-1,k=L;j>=0;j--,k--){   //整数部分
        a[k]=s[j]-'0';
    }
    for(j=i+1,k=L+1;j<strlen(s);j++,k++){  //小数部分
        a[k]=s[j]-'0';
    }
}

void add(int a[],int b[],int N){ //处理小数最后一位四舍五入
    int i;
    for(i=2*L;i>L+N;i--){
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[i+1]>=5) a[i]++;
    for(i=L+N;i>0;i--){
        a[i]+=b[i];
        a[i-1] += a[i]/10;
        a[i]=a[i]%10;
    }
}

void output(int a[],int N){
    int i=0;
    while (i<=L && a[i]==0) i++;  //跳过前置0
    if(i>L) printf("%d",0);
    else{
        while (i<=L) printf("%d",a[i++]); //整数部分
    }
    printf("%c",'.');
    while (i<=L+N) printf("%d",a[i++]);  //小数部分
    printf("\n");
}

int main() {
    int A[2*L+1]={0}, B[2*L+1]={0};  //设置两个数组存放两个浮点数
    input(A);
    input(B);
    int N;
    scanf("%d",&N);
    add(A,B,N);  //A=A+B
    output(A,N);
    return 0;
}