#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct R
{
	int val;
	int y;
	int d;
	char m[7];
};



int cmp(const void* a,const void* b)
{
	return(((struct R*)a)->val-((struct R*)b)->val);
}



int month2idx(char*m)
{
	int i;
	static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(i=0;;i++)
    {if(!strcmp(m,month[i])) {return i;}}
}


int main()
{

	int T,N;
	struct R s[10001];
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%d",&N);
		for(int j=0;j<N;j++)
		{
			scanf("%d.%s%d",&s[j].d,s[j].m,&s[j].y);
		s[j].val=s[j].y*1000+month2idx(s[j].m)*20+s[j].d;
	    }
		qsort(s,N,sizeof(s[0]),cmp);
		printf("case #%d:\n",i);
		for(int k=0;k<N;k++)
		{
			printf("%d. %s %d\n",s[k].d,s[k].m,s[k].y);
		}
	}
}