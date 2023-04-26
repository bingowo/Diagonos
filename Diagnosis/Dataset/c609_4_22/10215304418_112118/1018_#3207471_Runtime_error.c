#include<stdio.h>
#include<stdlib.h>

int cmp(const void* x,const void* y){
    return *(int*)x-*(int*)y;
}

int main(){
	int n;
	scanf("%d",&n);
	int a[100010];
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	qsort(a+1,n,sizeof(a[0]),cmp);
	long long ans=0;
	for (int i=1;i<=n;i++)
		ans+=a[2*i]-a[2*i-1];
	printf("%lld\n",ans);
	return 0;
}
