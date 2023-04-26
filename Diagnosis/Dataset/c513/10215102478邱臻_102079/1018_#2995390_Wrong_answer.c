#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 40
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int input(int(*p)[N]){
	int i=0;
	char c;
	do{
		scanf("%d%c",&p[i++][N-1],&c);
	}while(c==',');
	return i; //记录数字的个数 
}
void mult(int *a,int n){
	int i;
	for(i=N-1;i>0;i--){
		a[i]*=n;
	}
	for(i=N-1;i<0;i--){
		a[i-1]+=a[i]/10;
		a[i]=a[i]%10;
	}
}
void add(int *a,int*b){
	int i;
	for(i=N-1;i>0;i--){
		a[i]+=b[i];
		a[i-1]+=a[i]/10;
		a[i]=a[i]%10; 
	}
}
void output(int *d){
	int i=0;
	while(i<N && d[i]==0)i++;  //没有开始输出 
	if(i>=N){
		printf("0\n");return ;
	}
	while(i<N){
		printf("%d",d[i++]);
	}
	printf("\n");
}
int main() {
	int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int p[26][N]={},d[10000]={};
	int i,j;
	int count=input(p);  //记录数字个数
	for(i=0;i<count;i++){
		for(j=0;j<count-i-1;j++){
			mult(p[i],prime[j]);
		}  //相乘过程中也会有大整数出现 
		add(d,p[i]);
	} 
	output(d); 
	return 0;
}