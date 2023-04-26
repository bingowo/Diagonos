#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct an
{
	char* ps;
	int val;
	char* hash;
};

typedef struct an ans;

int cmp(const void* a,const void* b) 
{
	ans m=*(ans*)a;
    ans n=*(ans*)b;
    if(m.val<n.val)
    	return -1;
    else if(m.val>n.val)
    	return 1;
    else if(m.val==0)
    	return strcmp(m.ps,n.ps);
    else
    	return strcmp(m.hash,n.hash);
    
}

void solve(ans* p)
{
	p->val=0;
	for(int j=0;p->ps[j]!='\0';j++)
	{
		if(p->ps[j]>='0' && p->ps[j]<='9')
		{
			for(int k=0;p->ps[j]>='0' && p->ps[j]<='9';k++,j++)
			{
				p->hash[k]=p->ps[j];
			}
			p->val=1;
			break;
		}
	}
}

int main()
{
	ans res[101];
	int i=0;
	for(i=0;scanf("%s",res[i].ps)!=EOF;i++)
	{
		solve(&res[i]);
	}
	qsort(res,i,sizeof(res[0]),cmp);
	for(int j=0;j<i;j++)
	{
		printf("%s ",res[j].ps);
	}
	return 0;
}