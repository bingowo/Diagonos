#include <stdio.h>
#include <string.h>
#define ll long long
const ll MOD = 1e9+7;
char s[1010] = {0};
int a[1010] = {0};
int main(void)
{
	scanf("%s",s);
	int n = strlen(s);
	if(n==1){
		printf("1");
		return 0;
	}
	if(s[0]==s[1]) a[0] = 1;
	else a[0] = 2;
	if(s[n-1] == s[n-2]) a[n-1] = 1;
	else a[n-1] = 2;
	for(int i=1;i<=n-2;i++){
		a[i] = 1;
		if(s[i]!=s[i-1]){
			if(s[i+1]!=s[i] && s[i+1]!=s[i-1]) a[i] = 3;
			else a[i] = 2;
		}
		else{
			if(s[i+1]!=s[i]) a[i] = 2;
			else a[i] = 1;
		}
	}
	ll res = 1;
	for(int i=0;i<=n-1;i++){
		res = res*a[i]%MOD;
	}
	printf("%lld",res%MOD);
	return 0;
}