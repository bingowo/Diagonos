#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int max(int a,int b){
	return a<b?b:a;
}
int main(int argc, char *argv[]) {
	char A[55],B[55];
	int a[26],b[26],result[26];
	int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int t,i,j,z,counta,countb,k,max1,flag;
	char c;
	scanf("%d",&t);  //输入问题数
	getchar();
	for(i=0;i<t;i++){
		for(j=0;j<26;j++){a[j]=0;b[j]=0;result[j]=0;}
		counta=0;countb=0;flag=0;
		scanf("%s",A);scanf("%s",B);  //目标字符串
		for(k=0,j=strlen(A)-1;j>=0;j--){
			if(A[j]!=','){
				if(a[k]!=0 || flag)a[k]=a[k]+(A[j]-'0')*10;
				else {a[k]=A[j]-'0';flag=1;}
			}
			else {
				k++;flag=0;
			}
		}
		counta=k+1;flag=0;
		for(k=0,j=strlen(B)-1;j>=0;j--){
			if(B[j]!=','){
				if(b[k]!=0 || flag)b[k]=b[k]+(B[j]-'0')*10;
				else {b[k]=B[j]-'0';flag=1;}
			}
			else{
				k++;flag=0;
			}
		}
		countb=k+1;max1=max(counta,countb);
		for(k=0;k<max1;k++){
			result[k]+=(a[k]+b[k]);
			if(result[k]>=prime[k]){
				result[k]-=prime[k];  //进位情况
				result[k+1]+=1; 
			}
		} 
		z=0;
		printf("case #%d:\n",i);
		if(result[k]!=0){
			for(z=k;z>=0;z--){
				printf("%d",result[z]);
				if(z!=0)printf(",");
			}
		}
		else {
			for(z=k-1;z>=0;z--){
				printf("%d",result[z]);
				if(z!=0)printf(",");
			}
		}
		printf("\n");
	} 
	return 0;
}