#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s{
	char str[16];
	int n[16];
	int k;
	int min;
};
int cmp(const void*a,const void*b)
{
	struct s *q,*p;
	q=(struct s*)a;p=(struct s*)b;
	if(q->min!=p->min) return (q->min)-(p->min);
	else{
		int i=0;
		while((q->str[i])==(p->str[i]))
		{
			i++;
		}
		if((q->str[i])>(p->str[i])) return 1;
		else return -1;
	}
}
int main()
{
	int N,i=0;
	struct s m[10001];
	scanf("%d",&N);
	for(i;i<N;i++) scanf("%s",m[i].str);
	for(i=0;i<N;i++)
	{
		int len=strlen(m[i].str),j=0,n=0,h=0;
		for(j;j<len;j++)
		{
			for(h;h<j;h++)
			{
				if(m[i].str[j]==m[i].str[h])
				{
					n-=1;
					break;
				 } 
			}
			n+=1;
		}
		m[i].k=n;
		int w=0,sum=1;
		m[i].n[0]=1;
		for(j=1;j<len;j++)
		{
			if(m[i].str[j]==m[i].str[j-1]) m[i].n[j]=m[i].n[j-1];
			else{
				m[i].n[j]=w;
				if(w==0) w=2;
				else w++;
			//	printf("%d\n",w);
			}
			sum=(n*sum)+m[i].n[j];
		}
		m[i].min=sum;
		
	}
	//printf("%d\n",m[1].min);
//	printf("%d\n",m[1].k);
	qsort(m,N,sizeof(m[0]),cmp);
	int e=0;
	for(e;e<N;e++) printf("%s\n",m[e].str);
	return 0;
	
}