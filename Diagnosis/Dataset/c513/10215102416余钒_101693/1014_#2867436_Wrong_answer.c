#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char num[305],ans[305];
int n,m,top=0;
int main() {
	scanf("%d%d",&n,&m);
	while(n) num[++top]=n%3,n/=3;
	int up=0;
	for(int i=1;i<=top;i++)
		 num[i]=num[i]+1+up,up=num[i]/3,num[i]%=3;
	if(up) num[++top]=up;
	for(int i=1;i<=top/2;i++){
		int tmp=num[i];
		num[i]=num[top-i+1],num[top-i+1]=tmp;
	}
	int res=-1,tot=0;
	while(m) m/=3,res++;
	for(int i=1;i<=top-res;i++){
		if(i==1 && up) ans[++tot]=num[i]+'0';
		else if(num[i]==0) ans[++tot]='2';
		else ans[++tot]=num[i]-1+'0';
	}
	if(top-res<=0) ans[++tot]='0';
	if(res>0){
		ans[++tot]='.';
		for(int i=top-res+1;i<=top;i++){
			if(i<=0) ans[++tot]='0';
			else if(num[i]==0) ans[++tot]='2';
			else ans[++tot]=num[i]-1+'0';
		}
	}
	while(ans[tot]=='0'&&res>0) tot--;
	if(ans[tot]=='.') tot--;
	ans[tot+1]='\0';
	printf("%s",ans+1);
	return 0;
}