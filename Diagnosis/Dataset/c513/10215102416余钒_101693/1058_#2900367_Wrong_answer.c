#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n,l;
char s[2000005];

int main() {
	int cnt1=0,cnt2=0;
	while(gets(s)!=NULL){
		if(s[0]==0 && cnt1==0) puts("");
		cnt2=0;
		for(int i=0;s[i];i++){
			if(cnt1>0){
				if(s[i]=='*'&&s[i+1]=='/') {
					i++;
					cnt1--;
				}
			}
			else if(s[i]=='/'){
				if(s[i+1]=='/'&&cnt2==0){
					printf("%d   !!\n",cnt2);
					puts(" ");
					break;
				}
				else if(s[i+1]=='*'&&cnt2==0) cnt1++;
				else putchar(s[i]);
			}
			else{
				if(s[i]=='"' && cnt2==0) cnt2++;
				else if(s[i]=='"' && cnt2==1) cnt2--;
				putchar(s[i]); 
			}
			if(s[i+1]==0&&cnt1==0) puts("");
		}
	}
	return 0;
}
