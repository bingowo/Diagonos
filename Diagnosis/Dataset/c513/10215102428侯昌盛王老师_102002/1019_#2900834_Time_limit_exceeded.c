#include <stdio.h>
#include <stdlib.h>
struct s{
	int score,win,lose,p;
};

int cmp(const void *a,const void *b)
{
	struct s *aa=(struct s*)a;
	struct s *bb=(struct s*)b;
	if((bb->score)>(aa->score)) return 1;
	else if((bb->win)>(aa->win)) return 1;
	else if((aa->lose)<(bb->lose)) return -1;
	else return (aa->p)-(bb->p);
}
int main()
{
	int n;
	long long m;
	scanf("%d %lld",&n,&m);
	while(n!=0 && m!=0)
	{
		int j=1;
		struct s num[n+1];
		for(j=1;j<n+1;j++)
		{
			num[j].score=0;num[j].win=0;num[j].lose=0;
			num[j].p=j;
		}
	
		int i=0;
		for(i;i<m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(c==1) {
				num[a].score+=3;
				num[a].win+=1;
				num[b].score-=1;
				num[b].lose-=1;
			}
			if(c==-1){
				num[a].score-=1;
				num[a].lose+=1;
				num[b].score+=3;
				num[b].win+=1;
				
			}
		//	printf("%d\n",num[a].p);
			
		}
		qsort(num,n,sizeof(num[0]),cmp);
		int k=1;
		for(k;k<=n;k++)
		{
			if(k!=n) printf("%d ",num[k].p);
			else printf("%d\n",num[k].p);
		}
		
		
	}
	return 0;
}