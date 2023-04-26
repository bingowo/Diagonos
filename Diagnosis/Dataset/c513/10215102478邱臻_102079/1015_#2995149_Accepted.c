#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void reverse(int *t,int len){
	int i=0,j=len-1;
	int x;
	for(i=0,j=len-1;i<=j;i++,j--){
		x=t[i];t[i]=t[j];t[j]=x;
	}
}
int max(int a,int b){
	return a>b?a:b;
}
int main() {
	int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int t,i,j,k,z;
	char A[100],B[100];
	int a[36],b[36],result[36];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++){
		for(j=0;j<36;j++){a[j]=0;b[j]=0;result[j]=0;}
		scanf("%s%s",A,B);
		for(j=0,k=0;j<strlen(A);j++){
		    if(A[j]!=','){
		    	if(A[j+1]!=','  && j!=strlen(A)-1)a[k]=A[j]-'0';
		    	else {
		    		a[k]=a[k]*10+A[j]-'0';
		    		k++;
				}
			}	
		}
		for(j=0,z=0;j<strlen(B);j++){
			if(B[j]!=','){
		    	if(B[j+1]!=',' && j!=strlen(B)-1)b[z]=B[j]-'0';
		    	else {
		    		b[z]=b[z]*10+B[j]-'0';
		    		z++;
				}
			}
		}
		reverse(a,k);reverse(b,z);  //个位数对齐
		for(j=0;j<max(k,z);j++){
			result[j]+=a[j]+b[j];
			if(result[j]>=prime[j]){
				result[j]=result[j]-prime[j];
				result[j+1]++;
			}
		}
		printf("case #%d:\n",i);
		if(result[j]==0){
		for(z=j-1;z>=0;z--){
			printf("%d",result[z]);
			if(z==0)printf("\n");
			else printf(",");
		}}
		else {
			for(z=j;z>=0;z--){
			printf("%d",result[z]);
			if(z==0)printf("\n");
			else printf(",");
		}
		} 
	}
	return 0;
}