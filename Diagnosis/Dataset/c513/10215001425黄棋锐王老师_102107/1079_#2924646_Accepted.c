#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b){
	return *(long long*)a-*(long long*)b;
}
 int main(){
		int i,T;
		scanf("%d",&T);
		for(i=0;i<T;i++){
			int n,m,j,L,U,co=1,k;
			long long a[1001]={0};
			long long b[1001*500]={0};
			scanf("%d %d",&n,&m);
			for(j=1;j<=n;j++){
				scanf("%ld",&a[j]);
				a[j]+=a[j-1];//sum(a[i]~a[j])=sa[j]-sa[i-1];
			}
			for(j=1;j<=n;j++) {
				for(k=j;k<=n;k++) b[co++]=a[k]-a[k-j];
			}
			qsort(b,co,sizeof(b[0]),cmp);
			for(j=1;j<=co;j++) b[j]+=b[j-1];
			printf("case #%d:\n",i);
			for(j=0;j<m;j++){
			scanf("%d %d",&L,&U);
			printf("%lld\n",b[U]-b[L-1]);
			}
		}
		return 0;
}