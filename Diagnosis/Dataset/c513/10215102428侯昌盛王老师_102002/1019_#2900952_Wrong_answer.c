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
	else if((aa->p)>(bb->p)) return -1;
}
int main()
{
	int n;
	long long m;
	scanf("%d %lld",&n,&m);
	while(n!=0 || m!=0)
	{
		int j=0;
		struct s num[n];
		for(j=0;j<n;j++)
		{
			num[j].score=0;num[j].win=0;num[j].lose=0;
			num[j].p=j+1;
		}

		int i=0;
		for(i;i<m;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(c==1) {
				num[a-1].score+=3;
				num[a-1].win+=1;
				num[b-1].score-=1;
				num[b-1].lose-=1;
			}
			if(c==-1){
				num[a-1].score-=1;
				num[a-1].lose+=1;
				num[b-1].score+=3;
				num[b-1].win+=1;
				
			}
			if(c==0)
			{
				num[a-1].score+=1;
				num[b-1].score+=1; 
			}
		//	printf("%d ",num[a-1].score);
		//	printf("%d\n",num[2].score);
			
		}
		qsort(num,n,sizeof(num[0]),cmp);
		int k=0;
		for(k;k<n;k++)
		{
			if(k!=n-1) printf("%d ",num[k].p);
			else printf("%d\n",num[k].p);
		}
		scanf("%d %lld",&n,&m);
		
		
	}
	return 0;
}