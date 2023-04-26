#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char s[501];
}STR;

int cmp(const void* a,const void* b)
{
	STR x,y;
	x=*(STR*)a;
	y=*(STR*)b;
	return strcmp(x.s,y.s);
}

void solve(int T)
{
	STR str[500];
	char t[501];
	if(T==0){
		getchar();
	}
	gets(t);
	int i,j=0,k=0;
	for (i=0;i<strlen(t);i++){
		if(t[i]==' '||t[i]==','||t[i]=='.'||t[i]=='!'||t[i]=='?'||t[i]=='\n'){
			str[j].s[k]='\0';
			j++;
			k=0;
		}
		else{
			str[j].s[k]=t[i];
			k++;
		}
	}
	qsort(str,j,sizeof(STR),cmp);
	for (i=1;i<j;i++){
		 if(strcmp(str[i].s,str[i-1].s)!=0){
		 	if(strlen(str[i-1].s)!=0){
		 		printf("%s ",str[i-1].s);
			 }
		}
	}
	printf("%s\n",str[j-1].s);
}
int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for (i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
 } 