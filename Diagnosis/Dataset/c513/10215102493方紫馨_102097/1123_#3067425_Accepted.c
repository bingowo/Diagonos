#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
	char str[21];
	int cnt;
};

int cmp1(const void* p1,const void* p2){
	char* a=(char*)p1;
	char* b=(char*)p2;
	return strcmp(a,b);
}

int cmp2(const void* p1,const void* p2){
	struct data* a=(struct data*)p1;
	struct data* b=(struct data*)p2;
	if(a->cnt!=b->cnt){
		return a->cnt-b->cnt;
	}else{
		return strcmp(a->str,b->str);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	char s[200000][21];
	struct data DNA[200000];
	for(int k=0;k<n;k++){
		scanf("%s",s[k]);
	}
	qsort(s,n,sizeof(s[0]),cmp1);
	
	int a=0;
	strcpy(DNA[a].str,s[0]);
	DNA[a].cnt=1;
	for(int i=1;i<n;i++){
		if(strcmp(DNA[a].str,s[i])==0){
			DNA[a].cnt++;
		}else{
			a++;
			strcpy(DNA[a].str,s[i]);
			DNA[a].cnt=1;
		}
	}
	qsort(DNA,a+1,sizeof(DNA[0]),cmp2);
	for(int i=0;i<a+1;i++){
		printf("%s\n",DNA[i].str);
	}
	
	return 0;
}