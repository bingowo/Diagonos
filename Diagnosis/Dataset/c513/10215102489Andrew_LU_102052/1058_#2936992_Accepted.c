#include <stdio.h>
#include <string.h>
int main(){
	char s;
	char ans[50005];
	char t;
	int f=0,ff=0,l=0,cnt,fff=0;
	while(scanf("%c",&s)!=EOF){
		//if(fff==1) printf("%d",f);
		if(s=='\n') {
			t=s;
			if(l!=2 && ff==0)
			 ans[strlen(ans)]=s;
			l=0;
			cnt=0;
			continue;
		}
		else if((s==34 || s==39) && ff==0 && l==0 && (t!=92 || (fff%2==1))){
			f++;
			f=f%2;
		}
		else if(s==47 && f%2==0 && t==47 && ff==0){
			if(cnt==1) l=2;
			l=1;
		}
		else if(s==42 && t==47 && l==0 && f%2==0){
			ff=1;
			s=0;
		}
		else if(s==47 && t==42 && f%2==0){
			ff=-1;
			s=15;
		}
		if(s==t && t==92) fff++;
		else fff=0;
		//printf("%c",s);
		if(t==47 && l==0 && (ff==0 || ff==-1)) ans[strlen(ans)]=t;
		if(l==0 && ff==0 && s!=47){
			//printf("\n%c",s);
			ans[strlen(ans)]=s;
		}
		t=s;
		if(ff==-1) ff=0;
		if(s!=32) cnt++;
		//printf("fff=%d f=%d\n",fff,f);
	}
	printf("%s",ans);
}