#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[1000500];

int main(){
	scanf("%s",s);
	int dp[128]={-1};
	long long len=strlen(s),p1=0,p2=1;
	long long maxlen=1,maxindex=0,nowlen=1;
	dp[s[p1]]=0;
	for(;p2<len;p2++){
		if(dp[s[p2]]!=-1){
		    for(;p1<dp[s[p2]];p1++)dp[s[p1]]=-1;
		    dp[s[p1]] = p2;
		}
		else{
		    dp[s[p2]] = p2;
		    nowlen = p2-p1;
		    if(maxlen<nowlen){
		        maxindex = p2 -nowlen + 1;
		        maxlen = nowlen;
		    }
		}
	}
	for(int i=0;i<maxlen;i++)printf("%c",s[maxindex+i]);
	
	return 0;
}