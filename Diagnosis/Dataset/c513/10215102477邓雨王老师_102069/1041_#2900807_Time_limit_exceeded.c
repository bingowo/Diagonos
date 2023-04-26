#include<stdio.h>
#include<string.h>
int main(){
	char s[51];
	scanf("%s",&s);
	int i=0;
	int max=1;
	int count=1;
	while(i<=48){
		if(s[i]=='|'&&s[i+1]=='-'){
			count++;
			i++;
			max=(count>max)?count:max;
		}
		else if(s[i]=='-'&&s[i+1]=='|'){
			count++;
			i++;
			max=(count>max)?count:max;
		}
		else if(s[i]=='-'&&s[i+1]=='-'||s[i]=='|'&&s[i+1]=='|'){
			count=1;
			i++;
	}
}
	printf("%d",max);
}