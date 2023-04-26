#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long f(int n,int m){
    if(n<m) return 0;
    if(n==m) return 1;
    return 2*f(n-1,m)-f(n-1-m,m)+(1<<(n-m-1));
	
}
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)&&n!=-1&&m!=-1)
	{
		long long ans=f(n,m);
		printf("%lld\n",ans);
		
	}
	
	return 0;
}