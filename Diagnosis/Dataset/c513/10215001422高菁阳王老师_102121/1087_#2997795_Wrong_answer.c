#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Add(char A[],int k){
	int i=k;
	while(i>0){
		A[i]++;
		if(A[i]<='9') return i;
		A[i]='0';
		i--;
	}
	return i;
}
int main(int argc, char *argv[]) {
	int n,k;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		printf("case #%d:\n",k);
		char A[101]={'0'};
		scanf("%s",A+1);
		int len=strlen(A);
		int i,j;
		Add(A,len-1);
		for(i=1;i<len;i++){
			if (A[i]==A[i-1]) break;
		}
		if(i!=len){
			i=Add(A,i);
			while(i>0){
				if(A[i]!=A[i-1]) break;
				i=Add(A,i);
			}
			for(j=i+1;j<len;j++)
			A[j] = (j-i+1)%2+'0'; 
		}
		if(A[0]!='0') printf("%c",A[0]);
        printf("%s\n",A+1);

	}
	return 0;
}