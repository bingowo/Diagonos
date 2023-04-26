#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s{
	char str[16];
	int res[128];
	int res2[128];
	int n[16];
	long long int k;
	long long int min;
};
int cmp(const void*a,const void*b)
{
	struct s *q,*p;
	q=(struct s*)a;p=(struct s*)b;
	if((q->min)>(p->min)) return 1;
	else if((q->min)<(p->min)) return -1;
	else{
		int i=0;
		int len1=strlen(q->str);
		int len2=strlen(p->str);
		while((q->str[i])==(p->str[i])&&i<len1&&i<len2)
		{
			i++;
		}
		if(i==len1) return -1;
		else if(i==len2) return 1;
		else if((q->str[i])>(p->str[i])) return 1;
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
		int q=0;
		for(q;q<len;q++) m[i].res2[q]=0;
		for(j;j<len;j++)
		{
			m[i].res2[m[i].str[j]]=1;
		}
		for(j=0;j<=128;j++) if(m[i].res2[j]!=0) n++; 
		if(n<2) n=2;
		m[i].k=n;
		
		int w=0;
		long long sum=1;
		int ee=0;
		for(ee;ee<=128;ee++) m[i].res[ee]=-1;
		m[i].n[0]=1;
		m[i].res[m[i].str[0]]=1;
		for(j=1;j<len;j++)
		{
		//	printf("%d\n",m[i].res[m[i].str[j]]);
			if(m[i].res[m[i].str[j]]==-1)
			{
				m[i].res[m[i].str[j]]=w;
				m[i].n[j]=w;
				if(w==0) w=2;
				else w++;
			//	printf("ssss\n");
			}
			else{
				m[i].n[j]=m[i].res[m[i].str[j]];
			}
		//	printf("%d\n",m[i].n[j]);
			sum=(n*sum)+m[i].n[j];
			//printf("%d\n",sum);
		}
		m[i].min=sum;
		
	}
//	printf("%lld\n",m[0].min);
//	printf("%d\n",m[1].min);
	qsort(m,N,sizeof(m[0]),cmp);
	int e=0;
	for(e;e<N;e++) printf("%s\n",m[e].str);
	return 0;
	
}