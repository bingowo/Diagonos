#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b){
	char *p1=*((char **)a);
	char *p2=*((char **)b);
	char *pp1;
	char *pp2;
	int i=0;
	while(*(p1+i)!='@')
	i++;
	pp1=p1+i+1;
	i=0;
	while(*(p2+i)!='@')
	i++;
	pp2=p2+i+1;
	if(strcmp(pp1,pp2)==0)
	return strcmp(p2,p1);
	return strcmp(pp1,pp2);
}

	char s[1000004],*p;
int main(){
	char **email;
	int N;
	scanf("%d",&N);
	email=(char **)malloc(N*sizeof(char *));
	while(N--){
		scanf("%s",&s);
		int len=strlen(s);
		p=(char *)malloc(len+1);
		strcpy(p,s);
		*(email+N)=p;
	}
	qsort(email,N,sizeof(char *),cmp);
	for(int i=0;i<N;i++)
	printf("%s\n",email[i]);
	for(int i=0;i<N;i++){
		p=email[i];
		free(p);
	}
	free(email);
	return 0;
}