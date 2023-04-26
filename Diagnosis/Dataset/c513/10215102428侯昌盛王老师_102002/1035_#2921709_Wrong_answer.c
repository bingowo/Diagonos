#include <stdio.h>
#include <stdlib.h>

struct s{
	long long int r;
	long long int h;
	long long int s1;
	long long int s2;

};

int cmp(const void*a,const void*b)
{
	struct s *q,*p;
	q=(struct s*)a;
	p=(struct s*)b;
	return (p->s1)-(q->s1);
	
}



int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	struct s a[n];
	int i=0;
	for(i;i<n;i++){
		scanf("%lld %lld",&a[i].r,&a[i].h);
		a[i].s1=a[i].r*2*a[i].h;
		a[i].s2=a[i].r*a[i].r+a[i].r*2*a[i].h;
	}
	qsort(a,n,sizeof(a[0]),cmp);
	
	int j;
	long long int max=0,sum;
	for(i=0;i<n;i++)
	{
		sum=a[i].s2;
		int count=1;
		for(j=0;j<n&&count<m;j++){
			if(i==j || a[j].s2>a[i].s2) continue;
			sum+=a[j].s1;
			count++;
		}
		if(count==m) {
			if(sum>max) max=sum;
		}
	}
	printf("%lld\n",max);
	return 0;
	
}