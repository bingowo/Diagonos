#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		char s[20];
		scanf("%s",s);
		int len,a,res;
		len=strlen(s);
		res=0;
		for(int j=0;j<len;j++){
			if(s[j]=='-') a=-1;
			if(s[j]=='0') a=0;
			if(s[j]=='1') a=1;
			res=res*3+a;
		}
		printf("case #%d:\n",i);
		printf("%d\n",res);
	}
	return 0;
}