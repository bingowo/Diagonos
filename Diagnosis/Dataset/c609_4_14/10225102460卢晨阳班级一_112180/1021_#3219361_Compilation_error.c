#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
	char* s1; char* s2;
	char ch1, ch2;
	s1 = (char*) a;
	s2 = (char*) b;
	while (*s1 && *s2)
	{
		ch1 = (*s1) >= 'a' ? *s1 - 32 : *s1;
		ch2 = (*s2) >= 'a' ? *s2 - 32 : *s2;	// 转换为大写
		if (p[ch1 - 'A'] != p[ch2 - 'A'])
			return p[ch1 - 'A'] - p[ch2 - 'A'];
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
	int p[26]={0};
	char c;
	int i=0;
	while(scanf("%c",&c)!=-1&&c!='\n'){
		p[c-'A']=i;
	}
	char q[101][100];
	char final;
	int cnt=0;
	while(scanf("%s%c",q[cnt],&final)!=-1&&final!='\n')
		cnt++;
	for(int j=0;j<cnt+1;j++)
		printf("%s ",q[j]);
	printf("\n");
	qsort(q,cnt,sizeof(q[0]),cmp);
	if(scanf("%c",&final)!=-1)
		goto begin;
	else
	return 0;
}
