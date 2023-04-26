#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		char s[100];
		scanf("%s",s);
		int ret=0;
		for(int i=0;i<strlen(s);i++){
			ret*=3;
			if(s[i]=='-')ret-=1;
			else if(s[i]=='1')ret+=1;
		}
		printf("case #%d:\n%d\n",cas++,ret);
	}
}