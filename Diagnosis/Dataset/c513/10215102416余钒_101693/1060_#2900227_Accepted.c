#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n,l;
char s[10005];

int main() {
	scanf("%s",s+1);
	l=strlen(s+1);
	int ans=0;
	for(int L=1;L<=l;L++){
		int R;
		if(s[L]<='0'||s[L]>'9') continue;
		for(R=L+1;R<=l;R++)
			if(s[R]>'9'||s[R]<'0') break;
		if(R-L>ans) ans=R-L;
	}
	printf("%d\n",ans);
	return 0;
}