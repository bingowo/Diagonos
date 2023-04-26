#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct an
{
	char s[21];
	int val=0;
};

typedef struct an ans;

int cmp(const void* a,const void* b) 
{
	ans m=*(ans*)a;
    ans n=*(ans*)b;
    if(m.val==n.val)
    {
    	return strcmp(m.s,n.s);
	}
	else
	{
		return n.val-m.val;
	}
}

void solve(ans* p)
{
	char hash[128]={'\0'};
	for(int i=0;p->s[i]!='\0';i++)
	{
		if(hash[p->s[i]]=='\0')
		{
			p->val++;
			hash[p->s[i]]=1;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		printf("case #%d:\n",i);
		int num;
		scanf("%d",&num);
		ans res[num];
		for(int j=0;j<num;j++)
		{
			scanf("%s",res[j].s);
			solve(&res[j]);
		}
		qsort(res,num,sizeof(ans[0]),cmp);
		for(int j=0;j<num;j++)
		{
			printf("%s\n",res[j].s);
		}
	}
	return 0;
}