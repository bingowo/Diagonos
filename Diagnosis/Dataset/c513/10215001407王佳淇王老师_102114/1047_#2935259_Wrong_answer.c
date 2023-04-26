#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int T;
	scanf("%d",&T);
	char s[100000];
	for (int v=0;v<T;v++){
		scanf("%s\n",s);
		printf("case #%d:\n",v);
		int count=0;
		for(int i=0;i<strlen(s);i++)
		{
			if(s[i]==s[i+1]){ count++;continue;}
			else {count++;printf("%d%c",count,s[i]);count=0;}		
	}
	printf("\n");
}return 0;}