#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T;
long long a,b,n,M,ans;
int main(){
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%lld%lld%lld",&a,&b,&n);
		ans=M=1;
		for(int i=1;i<=n;i++) M*=10;
		for(int i=1;i<=b;i++) ans=(ans*a)%M;
		printf("case #%d:\n",c);
		int cnt=0;
		while(M>ans) M/=10,cnt++;
		if(ans==0) cnt--;
		for(int i=1;i<cnt;i++) printf("0");
		printf("%lld\n",ans);
	}
	return 0;
}