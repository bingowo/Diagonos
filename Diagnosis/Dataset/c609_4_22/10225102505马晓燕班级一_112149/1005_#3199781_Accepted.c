#include<stdio.h>
#include<string.h>
int trans(char n[],int len,int *p){
	int ten=0;
	for(int i=0;i<len;i++){
		ten = ten * 3 + p[n[i]];
	}
	return ten;
}
int main(){
	int t;
	scanf("%d ",&t);
	int table[128]={0};
	table['1']=1,table['-']=-1,table['0']=0;
	
	for(int i=0;i<t;i++){
		char n[100]={0};
		scanf("%s",n);
		int len = strlen(n);
		int ret=trans(n,len,table);
		printf("case #%d:\n",i);
		printf("%d\n",ret);
	}

	return 0;
}