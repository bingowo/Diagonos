#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define L 500
void Input(int a[])   //input a float number
{
    char s[L+1];
    scanf("%s",s);    
    int i=0,j,k;
    while(s[i] && s[i]!='.') i++; //定位小数点

    for(j=i-1,k=L;j>=0;j--,k--) 
         a[k] = s[j]-'0';  //整数部分
    for(j=i+1,k=L+1;j<strlen(s);j++,k++) 
         a[k] = s[j]-'0';   //小数部分
}
int cmp(int a[], int b[])
{	
	int ret = 0;
	int i;
	for(i = 0 ; i < L+1; i ++){
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
void add(int a[],int b[],int N)
{   int i;
    for(i=2*L;i>L+N;i--)
    {
        a[i] -= b[i];
        if(a[i]<0){
            a[i-1]-=1;
            a[i]+=10;
        }
    }
    if(a[i+1] >= 5) a[i]++;
    for(i=L+N;i>0;i--)
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
    printf("%c",'.');
    while(i<=L+N) printf("%d",a[i++]);  //小数部分
    printf("\n");
}

int main(){
    int A[2*L+1]={0}, B[2*L+1]={0},N;
    Input(A);
    Input(B);    
    scanf("%d",&N);
	int m=cmp(A,B);
    if(m==1){
        add(A,B,N);
        output(A,N);
    }else{
        add(B,A,N);
        printf("-");
        output(B,N);
    }
    
    
}