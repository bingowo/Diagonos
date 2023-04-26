#include <stdio.h>
#include <string.h>
char s[1010] = {0};
int a[1010] = {0};
typedef struct{
	int cnt;
	int v[1010];
}BIGINT;
BIGINT MUL(BIGINT a,int b){
	BIGINT res = {0,{0}};
	res.cnt = a.cnt;
	int carry = 0,i = 0;
	for(i=0;i<a.cnt;i++){
		int temp = a.v[i]*b+carry;
		res.v[i] = temp%10;
		carry = temp/10;
	}
	while(carry>0){
		int temp = res.v[i]+carry;
		res.v[i++] = temp%10;
		res.cnt = i;
		carry = temp/10;
	}
	return res;
}
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
	BIGINT R = {1,{1}};
	for(int i=0;i<n;i++){
		R = MUL(R,a[i]);
	}
	for(int i=R.cnt-1;i>=0;i--)
		printf("%d",R.v[i]);
	return 0;
}