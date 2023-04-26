#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T,n;
unsigned long long a,b,ans=0;
int main() {
	scanf("%llu%llu",&a,&b);
	while(a!=0 && b!=0){
		if(a>b) ans+=b*4*(a/b),a%=b;
		else ans+=a*4*(b/a),b%=a;
	}
	printf("%llu\n",ans);
	return 0;
}