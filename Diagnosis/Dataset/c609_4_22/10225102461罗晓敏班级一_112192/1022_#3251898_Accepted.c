#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b){       //交换地址
	int i,j;char *c=*(char**)a,*d=*(char**)b;
	for(i=0;c[i];i++){
		if(c[i]=='@')
			break;
	}
	for(j=0;d[j];j++){
		if(d[j]=='@')
			break;
	}
	int ret=strcmp(c+i+1,d+j+1);
	if(ret!=0)return ret;
	else return strcmp(d,c);
}
int main(){
	int n,i,len;
	scanf("%d",&n);
	char **email=(char**)malloc(n*sizeof(char*));
	char num[1000001],*p; 
	for(i=0;i<n;i++){
		scanf("%s",num);
		len=strlen(num);
		p=(char*)malloc(len+1);
		strcpy(p,num);
		*(email+i)=p;
	}
	qsort(email,n,sizeof(char*),cmp);
	for(i=0;i<n;i++){
		printf("%s\n",*(email+i));
		free(email[i]);
	}
	free(email);
}