#include<stdio.h>
#include<stdlib.h>


int cmp(const void*a,const void*b){
	return *(int*)a-*(int*)b;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int n,m;
		scanf("%d %d",&n,&m);
		int a[1001];
		for(int j=0;j<n;j++)
		scanf("%d",&a[j]);
		
		int cnt=0;
		long long b[500501];
		for(int j=0;j<n;j++){
			b[cnt]=a[j];
			cnt++;
			for(int k=j+1;k<n;k++){
				long long num=0;
				for(int l=j;l<=k;l++)
				num+=a[l];
				b[cnt]=num;
				cnt++;
			}
		}
		
		
		qsort(b,cnt,sizeof(b[0]),cmp);
//		printf("数列为：");
//		for(int j=0;j<cnt;j++)
//		printf("%d ",b[j]);
//		printf("\n");
		
		printf("case #%d:\n",i);
		for(int j=0;j<m;j++){
			int L,U;
			scanf("%d %d",&L,&U);
			long long sum=0;
			for(int k=L-1;k<U;k++)
			sum+=b[k];
			
			printf("%lld\n",sum);
		}
	}
	return 0;
}