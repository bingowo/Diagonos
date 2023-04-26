#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(const void*a,const void*b){
	char*a1=(char*)a;
	char*b1=(char*)b;
	return *a1>*b1;
}
int main(){
	int T;//题目 
	char str[201],s[201];//输入字符串  要输出的字符串
	scanf("%d\n",&T);
	for(int i=0;i<T;i++) {
	    gets(str);
		char m[201];//字母串 
		int len=strlen(str),l=0;
		for(int j=0;j<len;j++){
		if(!isalpha(str[j])) s[j]==str[j];//非字母原位放置 
		else { m[l]=str[j];//字母存入字母串 
		l++;
		s[j]='a'; //标记字母位置 
		}m[l]='\0';	
		}
		qsort(m,l,sizeof(char),cmp);//将字母排序 
		int r=0,v=0;
		for(;v<len;v++)
		{
			if(s[v]=='a') {s[v]=m[r++];}
		}s[v]='\0';
		printf("case #%d:\n",i);
		puts(s);
		printf("\n");
		memset(str,0,sizeof(str));
		memset(s,0,sizeof(s));
		memset(m,0,sizeof(m));
		
	}
	return 0;
}