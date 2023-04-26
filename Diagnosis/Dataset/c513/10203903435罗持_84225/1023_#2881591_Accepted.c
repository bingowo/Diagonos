#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
int cal(char *s)
{
	int res = -1;
	int len = strlen(s);
	int pos = 0;
	while(pos < len && !isdigit(s[pos])) pos++;
	while(pos<len && isdigit(s[pos]))
	{
		if(res == -1) res = 0;
		res = res * 10 + (s[pos]-'0');
		pos++;
	}
	return res;
}
int mycmp(const void*a,const void*b)
{
	char *aa = *(char**)a;
	char *bb = *(char**)b;
	int na = cal(aa);
	int nb = cal(bb);
	if(na == nb) return strcmp(aa,bb);
	else if(na==-1) return -1;
	else if(nb==-1) return 1;
	else 
	{
		if(na>nb) return 1;
		else return -1;
	}
}
int main(void)
{
	char *s[111];
	int len = 0;
	char ss[40];
	while(scanf("%s",ss)!=EOF)
	{
		strcpy(s[len]=(char*)malloc((strlen(ss)+5)*sizeof(char)),ss);
		len++;
	}
	qsort(s,len,sizeof(s[0]),mycmp);
	for(int i=0;i<len;i++) printf("%s ",s[i]);
	return 0;
}