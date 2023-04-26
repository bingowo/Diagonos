#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
	
	char s[10000];
	scanf("%s",s);
	long long ans=0;
	int len=strlen(s);
	for(int j=0;j<len;j++){
		if(s[j]=='-') ans-=pow(3,len-j-1);
		else ans+=(s[j]-'0')*pow(3,len-j-1);
	}
	printf("case #%d:\n",i);
	printf("%lld\n",ans);
	
	
	}
}
