#include<stdio.h>
#include<string.h>

int main(){
	int T;
	scanf("%d",&T);
	int k=0;
	while(T--){
		char a[1000];
		scanf("%s",a);
		int out=0;
		for(int i=0;i<strlen(a);i++){
			if(a[i]=='-')
			out=out*3-1;
			else if(a[i]=='0')
			out=out*3;
			else
			out=out*3+1;
		}
		printf("case #%d:\n%d\n",k,out);
		k++;
	}
	return 0; 
} 