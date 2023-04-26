#include<stdio.h>
#define MAX 50
int main(){
	char fence[MAX];
	int i=0,num=1,maxn=1;
	while(scanf("%c",&fence[i])!=EOF) i++; i=0; 
	while(fence[i+1]=='|'||fence[i+1]=='-'){
		if(fence[i]!=fence[i+1]) num++;
		else{if(num>=maxn)maxn=num;
			num=1;
		} 
		i++;
	}
	printf("%d",(maxn>num)?maxn:num);
	return 0;
}