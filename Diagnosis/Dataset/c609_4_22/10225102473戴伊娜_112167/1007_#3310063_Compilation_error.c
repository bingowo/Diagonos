#include <stdio.h>
#include <stdlib.h>

struct data
{
    long long d;
    int count;
}number;

int cmp(const void *a,const void *b)
 {
    number *m =(number*)a;
	number *n =(number*)b;
	if(m->count!=n->count)
	{
		return (n->count)-(m->count);
	}
	else{
		if(m->d>n->d)
        {
			return 1;
		}
		if(m->d<n->d)
		{
			return -1;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        number s[N];
        for(int j=0;j<N;j++)
            {
            scanf("%lld",&s[j].d);
        	s[j].count=0;
        }

        for(int j=0;j<N;j++)
        {
      		for(int k=0;k<64;k++)
            {
           		 if((s[j].d)&((long long)(1)<<k))
                 {
                	 s[j].count++;
                 }
            }
        }
        qsort(s,N,sizeof(number),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
        {
        	printf("%lld ",s[j].d);
        }
        printf("\n");
    }
	return 0;
}

