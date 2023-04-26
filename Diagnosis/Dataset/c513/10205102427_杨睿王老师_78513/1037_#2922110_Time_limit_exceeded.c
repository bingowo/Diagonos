//1037
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long ull;
int cmp(const void* a,const void* b){
	ull x= *(ull*)a;
	ull y= *(ull*)b;
	if(x>y) return -1;
	else return 1;
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
	for(int j=0;j<m;j++){
		ans+=a[0]-a[j];
	}
	//printf("%lld",ans);
	for(int i=0;i<n-m+1;i++){
		ull tmp=0;
		for(int j=i;j<i+m;j++){
			tmp+=a[i]-a[j];
		}
		if(tmp<ans){
			ans=tmp;
		}
	}
	printf("%lld",ans);
}