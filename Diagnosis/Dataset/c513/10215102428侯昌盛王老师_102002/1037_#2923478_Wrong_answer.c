#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
	long long int q,p;
	q=*(long long int*)a;
	p=*(long long int*)b;
	return p-q;
}
long long pick(long long*a,int n,int m)
{
	if(n==m){
		long long min=0;
		int i;
		for(i=1;i<n;i++) min+=(a[0]-a[i]);
		return min;
	}
	else{
		long long res=0;
		int i;
		for(i=1;i<m;i++) res+=a[0]-a[i];
		long long min;
		min=res;
		//printf("%lld\n",min);
		for(i=1;i<=n-m;i++){
			res=res-(a[i-1]-a[i])*(m-1)+(a[i]-a[i+m-1]);
		//	printf("%lld\n",res);
			if(res<min) min=res;
			//printf("%lld\n",min);
		
		}
		return min;
	}
}
int main()
{
	int n,m,i,j;
	long long res,min;
	scanf("%d %d",&n,&m);
	long long int a[1000001];
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	min=pick(a,n,m);
	
	
	printf("%lld\n",min);
	return 0;
}