#include<stdio.h>
#include<stdlib.h> 
int cmp(const void*a,const void*b){
	int an=0,bn=0;
	for(int m=0;m<64;m++){
		an+=((*(long long *)a<<m)&1);
		bn+=((*(long long *)b<<m)&1);
	}
	if(an!=bn)return (bn-an);
	else return (*(long long *)a-*(long long *)b);
}
int main(){
	int i,n,j,k,num;
	long long a[10010];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		for(j=0;j<num;j++){
			scanf("%lld",&a[j]);
		}
		qsort(a,num,sizeof(long long),cmp);
		printf("case #%d:",i);
		for(k=0;k<num;k++){
			printf("%lld ",a[k]);
		}
		printf("\n");
	}
	return 0;
}