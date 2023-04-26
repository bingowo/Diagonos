#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct{
	char s[31];
	char str[31];
	char num[31];
}STR;
int cmp(const void* p1,const void* p2){
	STR* a = (STR* )p1;
	STR* b = (STR* )p2;	
	if(strcmp(a->num,b->num)==0){
		for(int i=0;i<strlen(a->s)&&i<strlen(b->s);i++){
			int m=isdigit(a->s[i])-isdigit(b->s[i]);
			if(m!=0)
				return -m;
		}
		return strcmp(a->str,b->str);
	}
	if(strlen(a->num)==0&&strlen(b->num)==0){
		return strcmp(a->str,b->str);
	}
	if(strlen(a->num)!=strlen(b->num))
		return strlen(a->num)-strlen(b->num);		
	int k=0;
	while(a->num[k]==b->num[k])
		k++;
	return a->num[k]-b->num[k];
}
int main()
{
	STR word[100];
	int i=0;//表示字符串数目 
	while(scanf("%s",word[i].s)!=EOF){
		int a=0,b=0;
		for(int j=0;j<strlen(word[i].s);j++){
			if(isdigit(word[i].s[j]))
				word[i].num[a++]=word[i].s[j];
			else
				word[i].str[b++]=word[i].s[j];
		}
		word[i].num[a]='\0';
		word[i].str[b]='\0';
		i++;
	}
	qsort(word,i,sizeof(STR),cmp);
	int k=0;
	for(;k<i-1;k++){
		printf("%s ",word[k].s);
	}
	printf("%s",word[k].s);
	return 0;
}