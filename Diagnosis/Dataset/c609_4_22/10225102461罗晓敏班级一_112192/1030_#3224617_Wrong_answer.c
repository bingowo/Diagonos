#include <stdio.h>
#include <string.h>
double fou[26];       //frequency of utilization
int cmp(const void* a,const void* b){
	char c=toupper(*(char*)a),d=toupper(*(char*)b);
	if(fou[c-'A']>fou[d-'A']){
		return -1;
	}else if(fou[c-'A']<fou[d-'A']){
		return 1;
	}else{
		return *(char*)b-*(char*)a;
	}
}
int main(){
	int t,i,j;
	scanf("%d",&t);
	char num[101];
	for(i=0;i<t;i++){
		for(j=0;j<26;j++)scanf("%lf",&fou[j]);   //&不能丢，会SIGSEGV
		getchar();                               //用gets必须先用getchar把'\n'读取 
		gets(num);
		qsort(num,strlen(num),sizeof(char),cmp);
		printf("case #%d:\n%s\n",i,num);
	}
}