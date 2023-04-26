#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
unsigned long long t[75]={0,1,1,2};


int main()
{	
	int pro;scanf("%d",&pro);
	for(int i=4;i<75;i++){
		t[i]=t[i-1]+t[i-2]+t[i-3];
	}
	for(int index=0;index<pro;index++){
		int s;scanf("%d",&s);
		printf("case #%d:\n%llu\n",index,t[s]);
	}
	return 0;
}