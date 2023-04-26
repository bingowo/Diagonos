#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define L 500
void Input(int a[])   //input a float number
{
    char s[L+1];
    scanf("%s",s);    
    int j,k;
    for(j=strlen(s)-1,k=2*L;j>=0;j--,k--) 
         a[k] = s[j]-'0';
}
void minus1(int a[],int b[],int N)
{   int i;
    for(i=2*L;i>0;i--)
    {
        a[i] -= b[i];
        if(a[i]<0){
            a[i-1]-=1;
            a[i]+=10;
        }
    }
}
void output(int a[],int N)
{
    int i=0;
    while(i<=L && a[i]==0) i++;  //跳过前置0
    if(i>L) printf("%d",0);   //整数部分为0
    else
    {
        while(i<=L) printf("%d",a[i++]); //整数部分
    }
    printf("\n");
}

int main(){
    int A[2*L+1]={0}, B[2*L+1]={0},N;
    Input(A);
    Input(B);
    scanf("%d",&N);
    minus1(A,B,N); //A+=B
    output(A,N);
}