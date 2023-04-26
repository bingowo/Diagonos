#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n,l;
int solve(char* s1,char* s2,char* s){
	int l=strlen(s),l1=strlen(s1),l2=strlen(s2);
	int p1=-1e8,p2=1e8;
	for(int i=0;i+l1<=l;i++){
		char c=s[i+l1];
		s[i+l1]=0;
		if(strcmp(s1,s+i)==0){
			p1=i+l1-1,s[i+l1]=c;
			break;
		}
		s[i+l1]=c;
	}
	for(int i=l-l2;i>=0;i--){
		char c=s[i+l2];
		s[i+l2]=0;
		if(strcmp(s2,s+i)==0){
			p2=i,s[i+l2]=c;
			break;
		}
		s[i+l2]=c;
	}
	if(p2-p1>1e7) return -1;
	return p2-p1-1;
}
char s[10005],s1[105],s2[105];
int id[10005],cnt=0;
int main() {
	scanf("%d\n",&T);
	for(int c=0;c<T;c++){
		scanf("%s%s%s",s1,s2,s);
		int p1=solve(s1,s2,s);
		int p2=solve(s2,s1,s);
		printf("case #%d:\n",c);
		if(p1>p2) printf("%d\n",p1);
		else printf("%d\n",p2);
	}
	return 0;
}