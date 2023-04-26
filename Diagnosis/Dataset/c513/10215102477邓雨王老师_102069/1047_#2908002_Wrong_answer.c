#include<stdio.h>
#include<string.h>
int main(){
	int chance;
	scanf("%d\n",&chance);
	int i;
	for(i=0;i<chance;i++){
		printf("case #%d:\n",i);
		char s[501];
		scanf("%s",&s);
		char c=s[0];
		int sum=1;
		int j;
		for(j=0;j<strlen(s);j++){
			if(s[j]==s[j+1]){
				sum++;
				c=s[j];
			}
			else{
				if(sum>255){printf("255%c",c);sum=1;}
				else{
				printf("%d",sum);
				sum=1;
				printf("%c",c);
				c=s[j+1];}
			}
		}
	}
}