#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int t,i,y,x,z,k,q,j;
	char num[50];
	char num1[150];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",num);
		z=0;q=0;  
		for(j=strlen(num)-1;j>=2;j--){  //每一位小数的运算 
			y=num[j]-'0';k=0;  //y为余数 
			z=q;q=0;
			while(y!=0 || k<z ){
				if(k>=z)num1[k]='0';
				x=(y*10+(num1[k]-'0'))/8;
				y=(y*10+(num1[k]-'0'))%8;
				num1[k]=x+'0';q++;k++;  //商计入字符数组 
			}
		}
		z=q;
		printf("case #%d:\n0.",i);
		for(q=0;q<z;q++)printf("%c",num1[q]);
		printf("\n");
	}
	return 0;
}