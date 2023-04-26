#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void* a,const void* b){
	long long int *p1,*p2;
	p1=(long long int *)a;p2=(long long int *)b;
	return *p1>*p2?1:-1;
}
int main() {
	long long int t,result,i,j,k,u,l,total,n,m,cnt,z,a,num;
	long long int new_sum[500501],sum[1001],number[1001];
	scanf("%lld",&t);  //问题的组数
	for(i=0;i<t;i++){
		total=0;cnt=0;
		for(j=0;j<1001;j++){
			number[j]=0;sum[j]=0;
		}    //初始化数组 
		scanf("%lld %lld",&n,&m);  //记录数组总个数和新数组
		for(j=0;j<n;j++){
			scanf("%lld",&a);   //存入数组
			total+=a;
			number[j]=total;  //前缀和 
		}
		for(k=1;k<=n;k++){  //长度k不断增加 
			for(z=1;z<=n-k+1;z++){   //到最后一个可以有k长度的元素结束
			    cnt++;
			    sum[cnt]=number[z+k-1]-number[z-1];  //未排序的新数组 
			}
		}
		num=n*(n+1)/2;
		qsort(sum,num,sizeof(sum[0]),cmp);
		printf("case #%lld:\n",i);
		for(z=1;z<=cnt;z++)sum[z]+=sum[z-1];  //?
		for(k=0;k<m;k++){
			scanf("%lld %lld",&l,&u);  //输入需要求和的下标
			printf("%lld\n",sum[u]-sum[l-1]);
		} 
		 
	} 
	return 0;
}