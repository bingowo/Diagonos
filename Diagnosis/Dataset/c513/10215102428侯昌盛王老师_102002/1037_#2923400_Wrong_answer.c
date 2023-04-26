#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
	long long int q,p;
	q=*(long long int*)a;
	p=*(long long int*)b;
	return p-q;
}

int main()
{
	long long int n,m,i,j,res,min;
	scanf("%lld %lld",&n,&m);
	long long int a[n];
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	//printf("%lld %lld\n",a[4],a[5]);
	if(n==m){
		min=0;
		for(i=1;i<n;i++) min+=(a[0]-a[i]);
		printf("%lld\n",min);
	}
	else{
		res=0;
		for(i=1;i<m;i++) res+=a[0]-a[i];
		long long min=res;
		//printf("%lld\n",min);
		res=0;
		for(i=1;i<=n-m;i++){
			for(j=1;j<m;j++) res+=(a[i]-a[i+j]);
		//	printf("%lld\n",res);
			if(res<min) min=res;
			//printf("%lld\n",min);
			res=0;
		}
		printf("%lld\n",min);
	}
	
	//printf("%lld\n",min);
	return 0;
}