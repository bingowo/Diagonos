#include<stdio.h>
#include<string.h>
int main(){
	char a[1005];
	unsigned long long ans=1;
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		unsigned long long t=3;
		if(a[i-1]==a[i] || i==0) t--;
		if(a[i+1]==a[i] || i==strlen(a)-1) t--;
		ans=(ans*t)%1000000007;
	}
	printf("%llu",ans);
}