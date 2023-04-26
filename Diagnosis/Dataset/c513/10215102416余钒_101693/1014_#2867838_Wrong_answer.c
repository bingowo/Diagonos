#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char num[305],ans[305];
int n,m,top=0,pos=-1,add;
int main() {
	scanf("%d%d",&n,&m);
	while(n%3==0 && m%3==0) n/=3,m/=3;
	while(n) num[++top]=n%3,n/=3;
	while(m) pos++,m/=3;
	add=top+1;
	if(pos+1>add) add=pos+1;
	int up=0,cnt=0;
	for(int i=1;i<=add;i++){
		num[i]=num[i]+up+1;
		up=num[i]/3,num[i]%=3;
	}
	if(up) num[++add]=up;
//	for(int i=1;i<=add;i++) printf("%d ",num[i]);
	for(int i=1;i<=add;i++){
		if(num[i]==0) ans[++cnt]='2';
		else ans[++cnt]=num[i]-1+'0';
		if(i==pos) ans[++cnt]='.';
	}
//	for(int i=1;i<=add;i++) printf("%c ",ans[i]);
	for(int i=1;i<=cnt/2;i++)
		up=ans[i],ans[i]=ans[cnt-i+1],ans[cnt-i+1]=up;
	if(pos>0)	
		while(ans[cnt]=='0' || ans[cnt]=='.') cnt--;
	ans[cnt+1]='\0';
	for(int i=1;i<=cnt;i++){
		if(ans[i]!='0'||ans[i]=='0' && ans[i+1]=='.') printf("%s",ans+i),exit(0);
	}
	return 0;
}