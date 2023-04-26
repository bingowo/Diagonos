#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
	int p=*(int*)a;
	int q=*(int*)b;
	if(p>q) return 1;
	else return -1;
}
long long int s_sum(int *a,int l,int u)
{
	long long int sum=0;
	for(l;l<u;l++)
	{
		sum=sum+a[l];
	}
	return sum;
}
int main()
{
	int t,i;
	//printf("h");
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,m,j,w=0,r;
		//printf("h");
		scanf("%d %d",&n,&m);
		int a[n];
		int k=n*(n+1)/2;
		for(j=0;j<n;j++) scanf("%d",&a[j]);
		int s[k],e=0;
		//printf("%d\n",a[0]);
		
		while(w<n)
		{
			s[e]=a[w];
			for(r=1;r<n-w;r++)
			{
				s[e+1]=s[e]+a[w+r];
				e++;
			}
			w++;
			e++;
			//printf("e=%d\n",e);
		
		}
		//printf("e=%d\n",e);
		//printf("kk1=%d\n",s[5]);
		qsort(s,k,sizeof(s[0]),cmp);
		long long int sum1[m];
		//printf("kkk=%d\n",s[5]);
		int l,u,p=0;
		long long sum;
		for(p;p<m;p++)
		{
			scanf("%d %d",&l,&u);
			l--;
			sum=s_sum(s,l,u);
			sum1[p]=sum;
		}
		printf("case #%d:\n",i);
		int y=0;
		for(y;y<m;y++) printf("%lld\n",sum1[y]);
		
	
		
	}
}