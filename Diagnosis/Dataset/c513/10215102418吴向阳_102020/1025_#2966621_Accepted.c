#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Char{
	char a[25];
	int diff;
};

int cmp(const void *a,const void *b)
{
	struct Char *p1 = (struct Char *)a,*p2 = (struct Char *)b;
	if(p1->diff-p2->diff) return p2->diff-p1->diff;
	else
	{
		char *p=p1->a,*q=p2->a;
		while (*p && *q)
		{
			if(*p-*q>0) return 1;
			else if (*p-*q<0) return -1;
			else 
			{
				*p++;
				*q++;
			}
		}
		if(*p) return 1;
		else if (*q) return -1;
		else return 0;
	}
}

int main()
{
	int T,t;
	scanf("%d",&T);
	t=T;
	while (T)
	{
		int n;
		scanf("%d",&n);
		int m[128];
		struct Char ch[n];
		for(int i = 0; i < n; i++)
		{
			scanf("%s",ch[i].a);
			int len = strlen(ch[i].a);
			ch[i].diff = 0;
			for(int k = 0; k < 128; k++) m[k] = -1;
			for (int j = 0; j < len; j++)
			{
				if(m[ch[i].a[j]] == -1)
				{
					m[ch[i].a[j]] = 0;
					ch[i].diff++;
				}
			}
		}
		qsort(ch,n,sizeof(ch[0]),cmp);
		printf("case #%d:\n",t-T);
		for(int i = 0; i < n; i++) printf("%s\n",ch[i].a);
		T--;
	}
	return 0;
}