#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define L 500
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
    char s1[L+1];
    char s2[L+1];
    while(scanf("%s %s",s1,s2)!=EOF){
        int A[L+1]={0};
        int j,k;
        for(j=strlen(s1)-1,k=L;j>=0;j--,k--){
            A[k] = s1[j]-'0';
        } 
        int B[L+1]={0};
        for(j=strlen(s2)-1,k=L;j>=0;j--,k--){
            B[k] = s2[j]-'0';
        } 
        int m=cmp(A,B);
        if(m==1){
        	minus1(A,B);
        	output(A);
    	}else{
        	printf("-");
        	minus1(B,A);
        	output(B);
        
    	}
    }

}