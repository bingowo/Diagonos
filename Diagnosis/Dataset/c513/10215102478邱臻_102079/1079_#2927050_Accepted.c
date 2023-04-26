#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void* a,const void* b){
	long long int *p1,*p2;
	p1=(long long int *)a;p2=(long long int *)b;
	return *p1>*p2?1:-1;
}
int main() {
	long long int t,n,m,cnt,total,a,u,l,i,j,k,z;
	long long int sum[500501]={0},number[1001];
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		total=0;cnt=0;
		for(j=0;j<1001;j++)number[j]=0;
		scanf("%lld%lld",&n,&m);
		for(j=1;j<=n;j++){
			scanf("%lld",number+j);
			number[j]+=number[j-1];  //第一次前缀和 
		}
		for(k=1;k<=n;k++){
			for(z=1;z<=n-k+1;z++){
				cnt++;
				sum[cnt]=number[z+k-1]-number[z-1];
			}
		}
		qsort(sum,n*(n+1)/2,sizeof(sum[0]),cmp);
		printf("case #%lld:\n",i);
        for(z=1;z<=cnt;z++)sum[z]+=sum[z-1];  //第二次前缀和
		for(k=0;k<m;k++){
			scanf("%lld%lld",&l,&u);
			printf("%lld\n",sum[u]-sum[l-1]);
		}
	}
	return 0;
}