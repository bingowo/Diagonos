#include<stdio.h>
#include<string.h>
int main(){
	char a[1005];
	long long ans=1;
	long long num=1e9+7;
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		int t=3;
		if(a[i-1]==a[i] || i==0) t--;
		if(a[i+1]==a[i] || i==strlen(a)-1) t--;
		ans=(ans*t)%num;
	}
	printf("%lld",ans);
}