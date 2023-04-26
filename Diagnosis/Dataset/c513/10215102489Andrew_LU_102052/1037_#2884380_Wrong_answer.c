#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b){
	return *(int*)a>*(int *)b;
}
int main(){
	int n,m,i,j;
	int a[100005];
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort((void *)a,n,sizeof(a[0]),cmp1);
	for(i=0;i<n;i++){
		//printf("%d \n",a[i]);
	}
	long long s=0xffffff,t;
	for(i=m-1;i<n;i++){
		t=0;
		for(j=i-m+1;j<i;j++){
			t=t+a[i]-a[j];
		}
		//printf("%d",t);
		if(s>t) s=t;
	}
	printf("%lld",s);
}