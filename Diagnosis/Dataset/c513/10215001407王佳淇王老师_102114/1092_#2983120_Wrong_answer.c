#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
char * mul(char*s,int x){
		int temp[10000]={0};
		int i,j=0,n=strlen(s);
	for(i=0;i<n;i++) temp[i]=s[n-i-1]-'0';
	memset(s,0,sizeof(s));
    for(i=0;i<n;i++) temp[i]*=x;
    for(int v=0;v<n+1;v++){
				if(temp[v]>=10){
				temp[v+1]+=temp[v]/10;
				temp[v]%=10;}
			}
	for(int l=n+1;l>=0;l--) s[j++]=temp[l]+'0'; 
				
	return s; 
}


int main(){
	char s[10001];
	scanf("%s",s);
	int len=strlen(s);
	if(len ==1) printf("1");
	if(len==2){
		if(s[0]!=s[1]) printf("3");
		else printf("1");
	}
	if(len>2){
	int diff=1;
	char dp[1001]={0};
	if(s[0]==s[1]) dp[0]='1';
	else if(s[0]!=s[1]) dp[0]='2';
	for(int i=1;i<len-1;i++){
		if(s[i]!=s[i-1]) diff++;
		if(s[i]!=s[i+1]) diff++; 
		if(s[i-1]==s[i+1]) diff--;
		if(diff>1) mul(dp,diff);
		diff=1;
	}
	if(s[len-1]!=s[len-2]) 
	mul(dp,2);
	/*if(s[len-1]==s[len-2]) dp=dp[len-1];*/
	int z=0;
	while(dp[z]=='0') z++;
	for(int x=z;x<strlen(dp);x++) printf("%c",dp[x]);
}

	return 0;
}