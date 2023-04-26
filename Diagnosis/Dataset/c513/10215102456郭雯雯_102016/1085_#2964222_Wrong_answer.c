#include<stdio.h>
#include<string.h>
#define L 500

void input(int *a){
    char s[L+1];
    scanf("%s",s);
    int l=strlen(s);
    for(int j=0;j<l;j++)a[j]=s[j]-'0';//转换成的数组没有小数点
}

int max(int *a,int *b){
    int i=0;
    while(i<2*L+1&&a[i]==b[i])i++;
    if(i==2*L+1)return 1;
    if(a[i]>b[i])return 1;
    else if(a[i]<b[i])return 0;
    
}

void minu(int a[],int b[],int N){   
    int i;
    for(i=2*L;i>0;i--){
        if(a[i]>=b[i])a[i] -= b[i];
        else{a[i]=a[i]+10-b[i];a[i-1]--;}
    }
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
    if(max(a,b)){minu(a,b,n);output(a,n);}
    else {minu(b,a,n);printf("-");output(b,n);}
    
}