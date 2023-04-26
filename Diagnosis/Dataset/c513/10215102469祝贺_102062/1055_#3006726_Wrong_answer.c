#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s[1000500];

int main(){
	scanf("%s",s);
	int dp[129];
	memset(dp,-1,sizeof(int)*129);
	int maxlen=1,maxindex=0,nowlen=0,nowindex=0;

	for(int i = 0; i < strlen(s); i++){
		if(dp[s[i]] >= nowindex){
		    
		    if(maxlen < nowlen){
		        maxindex = nowindex;
		        maxlen = nowlen;
		    }
		    
		    nowindex = dp[s[i]]+1;
		    nowlen = i-nowindex+1;
		}
		else{
		    nowlen++;
		}
		dp[s[i]] = i;
	}
	
	for(int i=0;i<maxlen;i++)printf("%c",s[maxindex+i]);
	
	return 0;
}