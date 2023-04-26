#include <stdio.h>
#include <stdlib.h>

struct s{
	long long int r;
	long long int h;
	long long int s1;

};

int cmp(const void*a,const void*b)
{
	struct s *q,*p;
	q=(struct s*)a;
	p=(struct s*)b;
	q->s1;p->s1;
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
	}
	qsort(a,n,sizeof(a[0]),cmp);
	long long int max=0;
	for(i=0;i<m;i++)
	{
		if(a[i].r>max) max=a[i].r;
	}
	int sum;
	sum=max*max;
	for(i=0;i<m;i++) sum+=a[i].s1;
	printf("%d\n",sum);
	return 0;
	
	
	
	

}