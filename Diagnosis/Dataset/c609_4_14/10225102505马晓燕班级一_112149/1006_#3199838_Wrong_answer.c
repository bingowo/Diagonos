#include<stdio.h>
#include<string.h>
long long trans(char n[],int len){
	long long ten=0;
	int x=0;
	int table[128]={0};
	for(int i=0;i<128;i++){
		table[i]=-1;
	}
	table[n[0]]=1;
	for(int i=1;i<len;i++){
		if(table[n[i]] == -1){
			table[n[i]] = x;
			if(x == 0)
				x+=2;
			else
				x++;
		}
	}
	for(int i=0;i<len;i++){
		ten = ten * x + table[n[i]];
	}
	return ten;
}
int main(){
	int t;
	scanf("%d ",&t);
	
	for(int i=0;i<t;i++){
		char n[65]={0};
		scanf("%s",n);
		
		int len = strlen(n);
		long long ret=trans(n,len);
		
		printf("case #%d:\n",i);
		printf("%lld\n",ret);
	}
	return 0;
}