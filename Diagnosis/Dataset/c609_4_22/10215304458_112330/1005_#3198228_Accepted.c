#include<stdio.h>
#include<string.h>
int main(){
	int t,len,q,ans,i,j,n[40];
	char s[40];
	scanf("%d",&t);
	for(i=0;i<t;++i){
		scanf("%s",s);
		len=strlen(s);
		ans=0,q=1;
		for(j=0;j<len;++j){
			if(s[j]=='-') n[j]=-1;
			else n[j]=s[j]-'0';
		}
		for(j=len-1;~j;--j){
			ans+=n[j]*q;
			q*=3;
		}
		printf("case #%d:\n%d\n",i,ans);
	}
    return 0;
}