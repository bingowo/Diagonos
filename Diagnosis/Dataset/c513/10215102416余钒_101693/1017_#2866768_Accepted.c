#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int hash[300];
long long val[300];
char s[200];
long long solve(int l,int r){
	long long res=0,las=0;
	for(int i=l;i<=r;i++){
		long long nw=0;
		if(s[i]=='('){
			int cnt=1;
			for(int j=i+1;j<=r;j++){
				if(s[j]=='(') cnt++;
				else if(s[j]==')') cnt--;
				if(cnt==0){
					nw=1000*solve(i+1,j-1);
					i=j;
					break;
				}
			}
		}
		else nw=hash[s[i]];
		if(las>=nw) res+=las;
		else res-=las;
		las=nw;
	}
	res+=las;
	return res;
}
int main(){
	hash['I']=1,hash['V']=5,hash['X']=10,hash['L']=50,hash['C']=100,hash['D']=500,hash['M']=1000;
	scanf("%s",s);
	printf("%lld",solve(0,strlen(s)-1));
	return 0;
}