#include<stdio.h>
int cmp(const void*a,const void*b){
	int x,y;
	x=*(int*)a;
	y=*(int*)b;
	if(x>y) return 1;
	else return -1;
}
int main(){
	int chance;   //问题数
	scanf("%d",&chance);
	int i,j;
	for(i=0;i<chance;i++){
		int n,m; //n表示原始数组的元素个数，m表示问题个数
		scanf("%d%d",&n,&m);
		int a[n]; 
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		int b[n*(n+1)/2];
		int p=0,x,y;
		for(x=0;x<n;x++){
			int sum=0;
			for(y=x;y<n;y++){
				sum=sum+a[y];
				b[p++]=sum;
			}
		}
		qsort(b,p,sizeof(int),cmp);
		int L,U;
		int k;
		printf("case #%d:\n",i);
		for(j=0;j<m;j++){
			scanf("%d%d",&L,&U);
			int sum1=0;
			for(k=L-1;k<U;k++){
				sum1=sum1+b[k];
			}
			printf("%d\n",sum1);
		}
		
	} 
}