#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define L 500
void Input(int a[])   //input a float number
{
    char s[L+1];
    scanf("%s",s);    
    int j,k;
    for(j=strlen(s)-1,k=L;j>=0;j--,k--) 
         a[k] = s[j]-'0';
}
void minus1(int a[],int b[])
{   int i;
    for(i=L;i>0;i--)
    {
        a[i] -= b[i];
        if(a[i]<0){
            a[i-1]-=1;
            a[i]+=10;
        }
    }
}void minus2(int a[],int b[])
{   int i;
    for(i=L;i>0;i--)
    {
        b[i] -= a[i];
        if(b[i]<0){
            b[i-1]-=1;
            b[i]+=10;
        }
    }
}
int cmp(int a[], int b[])
{	
	int ret = 0;
	for(int i = 0 ; i < L+1; i ++){
		if(a[i] > b[i]){
			ret = 1;
			break;
		}else if(a[i] < b[i]){
			ret = -1;
			break;
		}
	}
	
	return ret;
}

void output(int a[])
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
    int A[L+1]={0}, B[L+1]={0};
    Input(A);
    Input(B);
    int m=cmp(A,B);
    printf("%d",m);
    minus1(A,B,N); //A+=B
 //   output(A,N);
}