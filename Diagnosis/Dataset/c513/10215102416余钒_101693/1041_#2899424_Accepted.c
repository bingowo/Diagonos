#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[10005];
int main() {
	scanf("%s",s);
	int l=strlen(s),ans=1;
	for(int i=0;i<l;i++)
		for(int j=i+1;j<l;j++){
			int f=0;
			for(int k=i+1;k<=j;k++){
				if(s[k]==s[k-1]) f=1;
			}
			if(!f&&j-i+1>ans) ans=j-i+1; 
		}
	printf("%d\n",ans);
	return 0; 
}