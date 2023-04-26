#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int A[500],B[500],C[500];
	char a[500],b[500];
	int i,j,z,x,flag;
	while(scanf("%s%s",a,b)){
		for(i=0;i<500;i++){A[i]=0;B[i]=0;C[i]=0;}  //数组初始化 
		for(i=strlen(a)-1,j=0;i>=0;i--,j++){A[j]=a[i]-'0';}
		for(i=strlen(b)-1,j=0;i>=0;i--,j++){B[j]=b[i]-'0';}   //大整数输入
		//个位对齐
		if(strlen(a)==1)printf("%d\n",A[i]-B[i]);
		else {
			for(i=0;i<strlen(a);i++){
				if(A[i]>=B[i])x=A[i]-B[i];
				else {
					x=A[i]+10-B[i];
					if(A[i+1]>0)A[i+1]--;
					else {
						z=1;
						while(A[i+z]==0){A[i+z]=9;z++;}
						A[i+z]--;
					}
				}  //减法计算
				C[i]=x; 
			}//结果储存 
			flag=0;
			for(i=strlen(a)-1;i>=0;i--){
				if(C[i]==0 && flag==0);
				else if(C[i]!=0){
					flag=1;
					printf("%d",C[i]);
				}
				else if(flag==1)printf("%d",C[i]);
			}
			printf("\n");
		}
		}
	return 0;
}