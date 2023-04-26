#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[10050];
int find(char*s,int* i){
	int tag=0,p=*i;
	for(;p+1<strlen(s);p++){
		if(s[p]=='0' && s[p+1]=='x'){
			p=p+2;tag=1;
			break;
		}
	}
	if(tag==1 && (isdigit(s[p]) || (s[p]>='a' && s[p]<='f'))){
		unsigned int num=0;int e=p;
		for(;e<strlen(s) && (isdigit(s[e]) || (s[e]>='a' && s[e]<='f'));e++){
			int t=isdigit(s[e])?s[e]-'0':s[e]-'a'+10;
			num=num*16+t;
		}
		printf("%u ",num);
		*i=e;
		return 1;
	}
	else *i=p+1;
	return 0;
}
int main(){
	scanf("%s",s);
	int i=0,flag=0;
	while(i<strlen(s)){
		if(find(s,&i)==1)flag=1;
	}
	if(flag==0)printf("-1 ");
	return 0;
} 
 
 