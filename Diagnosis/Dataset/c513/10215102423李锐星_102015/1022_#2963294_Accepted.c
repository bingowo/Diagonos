#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
char* get(char *s)
{
	while(*s!='@'){
		s++;
	}
	return s+1;
}

int cmp(const void* a,const void* b)
{
	int t;
	t=strcmp(get(*(char**)a),get(*(char**)b));
	return t?t:strcmp(*(char**)b,*(char**)a);
}

int main()
{
	int n;
	scanf("%d",&n);
	char **s;
	s=(char**)malloc(n*sizeof(char*));
	for (int i=0;i<n;i++){
		char t[1000001];
		scanf("%s",t);
		strcpy(s[i]=(char*)malloc(strlen(t)+1),t);
	}
	qsort(s,n,sizeof(s[0]),cmp);
	for(int i=0;i<n;i++){
		printf("%s\n",s[i]);
	}
	free(s);
	return 0;
}