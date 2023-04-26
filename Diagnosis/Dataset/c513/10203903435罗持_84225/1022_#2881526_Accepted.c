#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *getzhu(char *s)
{
	while(*s != '@') s++;
	return s+1;
}
int mycmp(const void*a, const void*b)
{
	int opt = strcmp(getzhu(*(char**)a),getzhu(*(char**)b));
	if(opt==0) return strcmp(*(char**)b,*(char**)a);
	else return opt;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	char **s = (char**)malloc((n+5)*sizeof(char*));
	for(int i=1;i<=n;i++)
	{
		char ss[1000010];
		scanf("%s",ss);
		strcpy(s[i]=(char*)malloc(strlen(ss)+5),ss);
	}
	qsort(s+1,n,sizeof(s[0]),mycmp);
	for(int i=1;i<=n;i++) printf("%s\n",s[i]);
	return 0;
}