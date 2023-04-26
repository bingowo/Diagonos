#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[305],res[805],tmp[805],ans[805];
int T;
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		for(int i=0; i<800; i++) res[i]=ans[i]=0;
		res[1]=1,res[2]=2,res[3]=5;
		int lft=3;
		scanf("%s",s);
		for(int i=2; s[i]!='\0'; i++) {
			int up=0;
			for(int j=lft; j; j--) {
				tmp[j]=res[j]*(s[i]-'0')+up;
				up=tmp[j]/10,tmp[j]%=10;
			}
			up=0;
			for(int j=lft; j; j--) {
				ans[j]=tmp[j]+ans[j]+up;
				up=ans[j]/10,ans[j]%=10;
			}
			int tot=0;
			for(int j=1; j<=lft+3; j++) {
				tot=tot*10,tot+=res[j];
				res[j]=tot/8;
				tot%=8;
			}
			lft+=3;
		}
		printf("case #%d:\n0.",c);
		for(int i=1; i<=lft-3; i++) printf("%d",ans[i]);
		puts("");
	}
	return 0;
}