#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 1000000007 
int ans=1;
char s[100005];
int main() {
	scanf("%s",s);
	for(int i=0;s[i];i++){
		int cnt=1;
		if(i!=0 && s[i-1]!=s[i]) cnt++;
		if(s[i+1]!=0 && s[i+1]!=s[i]) cnt++;
		if(i!=0 && s[i+1]!=0 && s[i+1]==s[i-1] && cnt==3 ) cnt--;
		ans=ans*cnt%M;
	}
	printf("%d\n",ans);
	return 0;
}
