#include<stdio.h>
#include<stdlib.h>

int cmp(const void* x,const void* y){
    return *(long long*)x-*(long long*)y;
}

int main(){
	int n;
	scanf("%lld",&n);
	long long a[100010];
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	qsort(a+1,n,sizeof(a[0]),cmp);
	long long ans=0;
	for (int i=1;i<=n;i++)
		ans+=a[2*i]-a[2*i-1];
	printf("%lld\n",ans);
	return 0;
}
