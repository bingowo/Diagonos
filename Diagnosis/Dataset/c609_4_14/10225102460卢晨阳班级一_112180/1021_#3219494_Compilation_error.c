#include<stdio.h>
#include<stdlib.h>

struct word{
	char m[100];
	int n[26];
}s[101];

int cmp(const void* a, const void* b)
{
	struct word*aa=(struct word*)a;
	struct word*bb=(struct word*)b;
	char* s1; char* s2;
	char ch1, ch2;
	s1 = (char*) aa->m;
	s2 = (char*) bb->m;
	while (*s1 && *s2)
	{
		ch1 = (*s1) >= 'a' ? *s1 - 32 : *s1;
		ch2 = (*s2) >= 'a' ? *s2 - 32 : *s2;	// 转换为大写
		if (aa->n[ch1 - 'A'] != aa->n[ch2 - 'A'])
			return aa->n[ch1 - 'A'] - aa->n[ch2 - 'A'];
		else
		{
			s1++;
			s2++;
		}
	}
	if (*s1 == 0)
		return -1;
	else
		return 1;
}

int main()
{
	begin:
	char ch[26];
	int i=0;
	while(scanf("%c",&ch[i])!=-1&&ch[i]!='\n'){
		for(int z=0;z<101;z++)
		s[z].n[ch[i]-'A']=i;
		i++;
	}
	char final;
	int cnt=0;
	while(scanf("%s%c",s[cnt].m,&final)!=-1&&final!='\n')
		cnt++;
	qsort(s,cnt,sizeof(s[0]),cmp);
	for(int j=0;j<cnt+1;j++)
	printf("%s ",s[j].m);
	printf("\n");
	if(scanf("%c",&final)!=-1)
		goto begin;
	else
	return 0;
}


