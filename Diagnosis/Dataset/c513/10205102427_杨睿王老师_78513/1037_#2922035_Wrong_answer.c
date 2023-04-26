//1037
#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ull;
int cmp(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	ull *a=(ull*)malloc(sizeof(ull)*n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	qsort(a,n,sizeof(ull),cmp);
	ull ans=0;
	ans=m*a[0];
	for(int j=0;j<m+1;j++){
		ans-=a[j];
	}
	for(int i=0;i<n-m+1;i++){
		ull tmp=0;
		tmp=m*a[i];
		for(int j=i;j<m+1;j++){
			tmp-=a[j];
		}
		if(tmp<ans){
			ans=tmp;
		}
	}
	printf("%lld",ans);
}