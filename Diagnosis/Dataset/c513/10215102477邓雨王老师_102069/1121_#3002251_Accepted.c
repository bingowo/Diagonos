#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int dp[100000];
int index=0;
void pushback(int n){
	dp[index++]=n;
} 
int main(){
	int chance;
	scanf("%d",&chance);
	int i,a[chance],sum=0;
	for(i=0;i<chance;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	char s[sum+1];
	memset(s,'0',sizeof(s));
	s[sum]='\0';
	for(i=0;i<chance;i++){
		int temp=index;
		pushback(a[i]);
		for(int j=0;j<temp;j++){
			pushback(dp[j]+a[i]);
			pushback(abs(dp[j]-a[i]));
		}
	}
	for(i=0;i<index;i++){
		s[dp[i]-1]='1';
	}
	printf("%s",s);
}