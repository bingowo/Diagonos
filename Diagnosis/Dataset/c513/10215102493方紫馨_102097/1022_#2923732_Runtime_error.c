#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char id[1000];
	char name[1000];
}email;
int cmp(const void* p1,const void* p2){
	email* a = (email*)p1;
	email* b = (email*)p2;
	if(strcmp(a->name,b->name))
		return strcmp(a->name,b->name);
	return strcmp(b->id,a->id);
}
int main()
{
	int n;
	scanf("%d",&n);
	email in[n];
	char s[2000];
	for(int i=0;i<n;i++){
		int j=0;
		scanf("%s",s);
		for(;j<strlen(s);j++){
			if(s[j]=='@')
				break;
			in[i].id[j]=s[j];
		}
		in[i].id[j++]='\0';
		int k=0;
		for(;j<strlen(s);j++,k++){
			in[i].name[k]=s[j];
		}
		in[i].name[k]='\0';
	}
	qsort(in,n,sizeof(email),cmp);
	for(int i=0;i<n;i++){
		printf("%s@%s\n",in[i].id,in[i].name);
	}
	return 0;
}