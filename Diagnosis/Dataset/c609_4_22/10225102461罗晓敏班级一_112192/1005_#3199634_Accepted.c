#include <stdio.h>
int f1(char num[]){
	int i,ret=0;
	for(i=0;num[i];i++){
		if(num[i]=='-')ret=ret*3-1;
		if(num[i]=='0')ret=ret*3;
		if(num[i]=='1')ret=ret*3+1;
	}
	return ret;
} 
int main(){
	int t,i;
	scanf("%d",&t);
	char num[32];
	for(i=0;i<t;i++){
		scanf("%s",num);
		printf("case #%d:\n%d\n",i,f1(num));
	}
}