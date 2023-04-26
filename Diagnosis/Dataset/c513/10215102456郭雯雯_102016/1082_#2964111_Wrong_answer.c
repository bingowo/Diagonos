#include<stdio.h>
#include<string.h>
#define L 500

void input(int *a){
    char s[L+1];
    scanf("%s",s);
    int l=strlen(s),i=0;
    while(i<l&&s[i]!='.')i++;//小数点位
    for(int j=i-1,k=L;j>=0;j--,k--)a[k]=s[j]-'0';
    for(int j=i+1,k=L+1;j<l;j++,k++)a[k]=s[j]-'0';//转换成的数组没有小数点
}

void add(int a[],int b[],int N)
{   int i;
    for(i=2*L;i>0;i--){
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
    if(a[L+N+1]>= 5) a[L+N]++;//进位
}

void output(int a[],int N)
{
    int i=0;
    while(i<=L && a[i]==0) i++;  //跳过前置0
    if(i>L) printf("%d",0);   //整数部分为0
    else{
        while(i<=L) printf("%d",a[i++]); //整数部分
    }
    printf("%c",'.');
    while(i<=L+N) printf("%d",a[i++]);  //小数部分
    printf("\n");
}

int main(){
    int a[2*L+1]={0},b[2*L+1]={0},n;
    input(a);input(b);
    scanf("%d",&n);
    add(a,b,n);
    output(a,n);
}