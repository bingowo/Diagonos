#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	char n1=*((char*)a),n2=*((char*)b);
	return n1-n2;
}
char stack[16];int sp=0;
void dfs(char *s,int len,int pos){
	int table[len];for(int i=0;i<len;i++)table[i]=0;
	if(pos<len){
		stack[sp++]=s[pos];
		for(int i=0;i<sp;i++)printf("%c",stack[i]);
		printf("\n");
		for(int i=pos+1;i<len;i++){
			if(table[pos]==0){
				dfs(s,len,i);
			}
		}
		sp--;
	}
	return;
}
int main(){
	int t;scanf("%d",&t);
	for(int m=0;m<t;m++){
		char s[20];scanf("%s",s);
		qsort(s,strlen(s),sizeof(s[0]),cmp);
		int begin=0;
		for(int end=1;end<strlen(s);end++){
			if(s[end]!=s[begin]){
				s[++begin]=s[end];
			}
		}
		printf("case #%d:\n",m);
		for(int i=0;i<=begin;i++){
			dfs(s,begin+1,i);
			sp=0;
		}
	}
	return 0;
} 
