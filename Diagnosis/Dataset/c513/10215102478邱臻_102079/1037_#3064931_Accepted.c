#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void* a,const void* b){
	long long x=*(long long*)a,y=*(long long*)b;
	if(x>y) return 1;
	else return -1;
}
int main(int argc, char *argv[]) {
	long long int n,m,ans,res,i;
	long long int num[1000005]={};
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	qsort(num,n,sizeof(num[0]),cmp);
	res=0;
	for(i=0;i<m;i++)res+=num[m-1]-num[i];
	ans=res;
	for(i=m;i<n;i++){
		res+=(num[i]-num[i-1])*m;
		res-=num[i]-num[i-m];
		ans=ans<res?ans:res;
	}
	printf("%lld",ans);
	return 0;
}