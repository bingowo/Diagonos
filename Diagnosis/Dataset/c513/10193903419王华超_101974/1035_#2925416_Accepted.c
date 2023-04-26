#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
typedef struct{
	long long h,r,ds,hs;
}column;
int cmp(const void*p1,const void*p2){
	column a=*((column*)p1),b=*((column*)p2);
	if(a.hs>b.hs){
		return -1;
	}
	else{
		return 1;
	}
}
int main()
{
   	int i,n,m;
   	scanf("%d %d",&n,&m);
   	column l[N];
   	for(i=0;i<n;i++){
   		scanf("%lld %lld",&l[i].r,&l[i].h);
   		l[i].ds=l[i].r*l[i].r;
   		l[i].hs=l[i].r*2*l[i].h;
	}
	qsort(l,n,sizeof(l[0]),cmp);
	long long max=0;
	for(i=0;i<n;i++){
		long long sum=l[i].hs+l[i].ds;
		int count=1;
		for(int j=0;j<n&&count<m;j++){
			if(i==j||l[j].r>l[i].r) continue;
			count++;
			sum+=l[j].hs;
		}
		if(count==m){
			if(sum>max) max=sum;
		}
	}
	printf("%lld",max);
	return 0;
}