#include <stdio.h>
#include <string.h>

void solve()
{
	char s[101],t[101];
	scanf("%s",s);
	int top=0,res=1,current=0;
	int len=strlen(s);
	int i;
	t[0]=s[0];
	for (i=1;i<len;i++){
		top++;
		t[top]=s[i];
		if(t[top-1]=='(')current=1;
		else if(t[top-1]=='[') current=2;
		else if(t[top-1]=='{') current=3;
		else current=0;
		if(t[top]=='('&&(current==1||current==3)) {
			res=0;
			break;
		}
		else if (t[top]=='['&&(current==2||current==1)){
			res=0;
			break;
		}
		else if(t[top]=='{'&&(current==3||current==2)){
			res=0;
			break;
		}
		if(t[top]==')'&&current==1) top-=2;
		else if(t[top]==']'&&current==2) top-=2;
		else if(t[top]=='}'&&current==3) top-=2;
		if(top<-1){
			res=0;
			break;
		}
		
	}
	if(top!=-1) res=0;
	if(res==1)printf("Yes\n");
	else printf("No\n");
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}