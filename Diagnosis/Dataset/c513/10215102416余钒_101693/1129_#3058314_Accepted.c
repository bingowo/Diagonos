#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
char s[100005];
int main() {
	scanf("%s",s);
	int pre=0,las=0,cnt=0;
	for(int i=0;s[i];i++){
		if(s[i]>='a'&&s[i]<='z') las++;
		else{
			cnt=cnt*10+s[i]-'0';
			if(s[i+1]<'0'||s[i+1]>'9'){
				for(int j=1;j<=cnt;j++)
					for(int k=pre;k<las;k++) printf("%c",s[k]);
				pre=las=i+1;
				cnt=0;
			} 
		}
	}
	if(pre!=las) for(int i=pre;i<las;i++) printf("%c",s[i]);
	return 0;
}