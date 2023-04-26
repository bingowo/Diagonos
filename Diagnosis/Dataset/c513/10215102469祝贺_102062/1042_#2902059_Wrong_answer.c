#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
	char n1=*((char*)a),n2=*((char*)b);
	return n1-n2;
}
void print(char* s,int start,int depth,int end){
	if(depth>end) return;
	for(int j=start;j<=depth;j++) printf("%c",s[j]);
	printf("\n");
	print(s,start,depth+1,end);
	for(int i=depth+2;i<=end;i++){
		for(int j=i;j<=end;j++){
			for(int k=start;k<=depth;k++) printf("%c",s[k]);
			for(int k=i;k<=j;k++)printf("%c",s[k]);
			printf("\n");
		}
	}
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
			print(s,i,i,begin);
		}
	}
	return 0;
} 
