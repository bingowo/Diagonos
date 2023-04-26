#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int t,i,j,k,l,z,x;
	char a[100],b[100];
	int n[27],m[27],result[27];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		for(j=0;j<27;j++){n[j]=0;m[j]=0;result[j]=0;}
		scanf("%s%s",a,b);
		printf("case #%d:\n",i);
		if(strcmp(a,"0")==0 && strcmp(b,"0")==0)printf("0\n");
		else {
		for(k=0,z=0;k<strlen(a);k++){
			if(isdigit(a[k]) && !isdigit(a[k+1])){
				n[z]=n[z]*10+a[k]-'0';
				z++;
			}  //是最后一位数字 
			else if(isdigit(a[k]) && isdigit(a[k+1])){
				n[z]=n[z]*10+a[k]-'0';
			}  //不是最后一位数字 
		}
		for(j=0,k=z-1;j<=k;j++,k--){x=n[j];n[j]=n[k];n[k]=x;}
		for(k=0,l=0;k<strlen(b);k++){
			if(isdigit(b[k]) && !isdigit(b[k+1])){
				m[l]=m[l]*10+b[k]-'0';
				l++;
			}  //是最后一位数字 
			else if(isdigit(b[k]) && isdigit(b[k+1])){
				m[l]=m[l]*10+b[k]-'0';
			}  //不是最后一位数字 
		}
		for(j=0,k=l-1;j<=k;j++,k--){x=m[j];m[j]=m[k];m[k]=x;}
		//个位数对齐
		x=l>=z?l:z; //取位数最多的数组
		for(j=0;j<x;j++){
			result[j]+=n[j]+m[j];
			if(result[j]>=prime[j]){result[j]-=prime[j];result[j+1]++;}  //向前进位 
		}
		j=26;
		while(result[j]==0)j--;
		for(j;j>=0;j--){
			printf("%d",result[j]);
			if(j!=0)printf(",");
			else printf("\n");
		} 
	}
	}
	return 0;
}