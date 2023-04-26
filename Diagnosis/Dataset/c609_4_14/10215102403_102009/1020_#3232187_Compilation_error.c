#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define MAXN 30

struct string_1{
	char a[MAXN];
	int flag;
	int num;
	int len;
}s[MAX];

int cmp(const void* a, const void* b){
	//struct string_1 s1, s2;
	string_1* s1 = (string_1*)a; 
	string_1* s2 = (string_1*)b;
	if(s1.flag==s2.flag){
		if(s1.num==s2.num) 
			return strcmp(s1.a+1,s2.a+1);
		else 
			return s1.num-s2.num;
	}
	else 
		return s1.flag-s2.flag;
}

int main(){
	int i=1,j=1,count;
	char c; c=getchar();
	while(c!='\n'){
		if(c!=' ') 
			s[i].a[j++]=c;
		else{ 
			s[i].len=j-1;
			i++;
			j=1; 
		}
		getchar();
	}
	if(c=='\n'){
		count=i;
		s[i].len=j-1;
	}
	for(i=1;i<=count;i++){
		s[i].flag=0;
		s[i].num=0;
		for(j=1;j<=s[i].len;j++){
			if(s[i].a[j]>='0'&&s[i].a[j]<='9'){
				s[i].num+=s[i].a[j]-'0';
				s[i].num*=10;
				s[i].flag=1;
			}
		}
	}
	qsort(s+1,count,sizeof(s[1]),cmp);
	for(i=1;i<=count;i++){
		for(j=1;j<=s[i].len;j++) 
			printf("%c",s[i].a[j]);
		printf(" ");
	}
	return 0;
}