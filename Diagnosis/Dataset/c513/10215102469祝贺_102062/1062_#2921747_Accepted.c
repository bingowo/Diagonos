#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
unsigned long long table[60]={0,1,2,4,8}; 

int main()
{
	for(int i=5;i<=50;i++){
		table[i]=table[i-1]+table[i-2]+table[i-3]+table[i-4];
	}
	//for(int i=1;i<=50;i++)printf("%llu\n",table[i]);
	long long t;
	scanf("%lld",&t);getchar();
	for(int index=0;index<t;index++){
		int s;scanf("%d",&s);
		printf("case #%d:\n%llu\n",index,table[s]);
	} 
	return 0;
}