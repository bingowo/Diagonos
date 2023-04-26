#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b){
	return *(long long*)a>*(long long *)b;
}
int main(){
	int n,m,i,j;
	long long a[100005];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	for(i=0;i<n;i++){
		//printf("%lld \n",a[i]);
	}
	long long s,t=0;
	for(j=0;j<m-1;j++){
		t=t+a[m-1]-a[j];
	}
	s=t;
	//printf("%lld\n\n",t);
	for(i=m;i<n;i++){
		t=t+m*(a[i]-a[i-1])-(a[i]-a[i-m]);
		if(t<s) s=t;
	}
	printf("%lld",s);
}