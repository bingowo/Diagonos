//1060
#include <stdio.h>
#include <string.h>
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int main(){
	char s[101];
	scanf("%s",&s);
	int i,l=strlen(s);
	int cnt=0;
	int ans=0;
	int flag=0;
	for(i=0;i<l;i++){
		if(flag==0){
			if(s[i]>'0'&&s[i]<='9'){
				cnt++;
				flag=1;
			}
		}
		else{
			if(s[i]>='0'&&s[i]<='9'){
				cnt++;
			}
			else{
				ans=max(ans,cnt);
				cnt=0;
				flag=0;
			}
		}
	}
	printf("%d",ans);
}