#include <stdio.h>
int cmp(const void* a,const void* b){
	int *c=(int *)a,*d=(int*)b;
	int i,j;
	for(i=0,j=0;c[i]+1&&d[j]+1;i++,j++){
		if(c[i]!=d[j]){
			return d[j]-c[i];
		}
	}
	if(c[i]==-1){
		return 1;
	}else{
		return -1;
	}
}
int main(){
	int t,i;
	scanf("%d",&t);
	int n,j,k;
	for(i=0;i<t;i++){
		scanf("%d",&n);
		int num[n][51];
		for(j=0;j<n;j++){
			k=0;
			while(scanf("%d",&num[j][k])!=EOF&&num[j][k]+1){
				k++;
			}
		}
		qsort(num,n,sizeof(num[0]),cmp);
		for(j=0;j<n;j++){
			for(k=0;num[j][k]+1;k++){
				printf("%d ",num[j][k]);
			}
			printf("\n");
		}
	}
} 