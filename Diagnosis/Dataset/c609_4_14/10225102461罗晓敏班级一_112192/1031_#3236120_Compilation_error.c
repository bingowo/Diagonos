#include <stdio.h>
int n,m,q;
void f(int a[],long long int s[]){
	int i,j,k;
	long long int ret;
	q=0;
	for(i=1;i<=n;i++){
		for(k=0;k+i<=n;k++){
			ret=0;
			for(j=k;j<k+i;j++){
				ret+=a[j];
			}
			s[q]=ret;q++;
		}
	}
}
int f2(const void *a,const void *b){
	return *(int*)a>*(int*)b?1:-1;
}
int main(){
	int t,i;scanf("%d",&t);
	int j,k;
	int l,u；
	long long int ret;
	for(i=0;i<t;i++){
		scanf("%d%d",&n,&m);
		int array[n]; 
		long long int subarray[n*(n+1)/2],retarray[m];
		for(j=0;j<n;j++){
			scanf("%d",&array[j]);
		}
		f(array,subarray);
		qsort(subarray,n*(n+1)/2,sizeof(long long int),f2);
		for(j=0;j<m;j++){
			ret=0;
			scanf("%d%d",&l,&u);
			for(k=l;k<=u;k++){
				ret+=subarray[k-1];
			}
			retarray[j]=ret;
		}
		printf("case #%d:\n",i);
		for(j=0;j<m;j++){
			printf("%lld\n",retarray[j]);
		}
	}
	return 0;
}