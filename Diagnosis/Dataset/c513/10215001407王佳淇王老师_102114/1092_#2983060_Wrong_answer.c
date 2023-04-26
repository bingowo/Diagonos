#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int main(){
	char s[1001];
	scanf("%s",s);
	int len=strlen(s);
	if(len ==1) printf("1");
	if(len==2){
		if(s[0]!=s[1]) printf("3");
		else printf("1");
	}
	if(len>2){
	int diff=1;
	int dp[1001]={0};
	if(s[0]==s[1]) dp[1]=1;
	else if(s[0]!=s[1]) dp[1]=2;
	for(int i=1;i<len-1;i++){
		if(s[i]!=s[i-1]) diff++;
		if(s[i]!=s[i+1]) diff++;
		dp[i+1]=dp[i]*diff;
		diff=1;		
	}
	if(s[len-1]!=s[len-2]) dp[len]=dp[len-1]*2;
	if(s[len-1]==s[len-2]) dp[len]=dp[len-1];
	printf("%d\n",dp[len]);
}

	return 0;
}