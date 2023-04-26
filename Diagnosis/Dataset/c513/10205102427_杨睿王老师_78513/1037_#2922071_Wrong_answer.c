//1037
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long ull;
int cmp(const void* a,const void* b){
	return *(int*)b-*(int*)a;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	ull *a=(ull*)malloc(sizeof(ull)*n);
	memset(a,0,n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	qsort(a,n,sizeof(ull),cmp);
	ull ans=0;
	ans=m*a[0];
	for(int j=0;j<m;j++){
		ans-=a[j];
	}
	//printf("%lld",ans);
	for(int i=0;i<n-m+1;i++){
		ull tmp=0;
		tmp=m*a[i];
		for(int j=i;j<i+m;j++){
			tmp-=a[j];
		}
		if(tmp<ans){
			ans=tmp;
		}
	}
	printf("%lld",ans);
}