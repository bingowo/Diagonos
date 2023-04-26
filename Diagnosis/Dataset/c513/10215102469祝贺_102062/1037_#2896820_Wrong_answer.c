#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
long long n,m;
int cmp(const void* a,const void* b){
	long long n1=*((long long *)a),n2=*((long long *)b);
	return n1>n2?-1:1;
}
int main(){
	scanf("%d%d",&n,&m);
	long long list[n],ret=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&list[i]);
	}
	qsort(list,n,sizeof(long long),cmp);
	for(int j=1;j<m;j++) ret+=list[0]-list[j];
	for(int i=1;i<=n-m;i++){
		long long ans=ret;
		ans=ans-(list[i-1]-list[i])*(m-1)+list[i]-list[i+m-1];
		if(ans<ret)ret=ans;
	}
	printf("%lld",ret);
}