#include<stdio.h>
#include<string.h>
int main(){
	char s[60];
	int cnt=1,ans=-1,i;
	scanf("%s",s);
	int len=strlen(s);
	for(i=1;i<len;++i){
		if(s[i]!=s[i-1]) ++cnt;
		else{
			ans=cnt>ans?cnt:ans;
			cnt=1;
		}
	}
	ans=cnt>ans?cnt:ans;
	printf("%d",ans); 
	return 0;
}