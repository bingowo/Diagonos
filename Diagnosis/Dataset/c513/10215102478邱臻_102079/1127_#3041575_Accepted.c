#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int lcg(int n,int m){
	int result,a,b;
	a=n>m?n:m;b=n<m?n:m;
	while((a%b)!=0){
		result=b;b=a%b;a=result;
	}
	return b;
}
int main(int argc, char *argv[]) {
	int t,n=0,m=0,i,j,m1,n1,c,flag;
	char num[100];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		n1=0;m1=0;flag=0; 
		scanf("%s",&num);
		for(j=0;j<strlen(num);j++){
			if(num[j]=='/')flag=1;
			else if(flag==0)n1=n1*10+(num[j]-'0');  //分子计算 
			else if(flag==1)m1=m1*10+(num[j]-'0');  //分母计算 
		}
		if(m==0){
			m=m1;n=n1;
		}
		else {
			n=m*n1+n*m1;m=m*m1;
			c=lcg(n,m);
			n=n/c;m=m/c;
		}
	}
	printf("%d/%d",n,m);
	return 0;
}