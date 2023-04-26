#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int n,cur=0,cnt=0;
struct node{
	int pos1,pos2;
}A[1005];
char s[500005];
int cmp(const void* a,const void* b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	if(strcmp(s+x.pos1,s+y.pos1)==0) return strcmp(s+x.pos2,s+y.pos2);
	return strcmp(s+x.pos1,s+y.pos1);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+cur);
		int l=strlen(s+cur);
		if(s[cur+4]!='s'){
			A[++cnt].pos1=cur+7;
			for(int j=7;s[cur+j];j++){
				if(s[cur+j]=='/'){
					A[cnt].pos2=cur+j+1;
					s[cur+j]='\0';
					break;
				}
			}
		}cur+=l,s[++cur]='\0';
	}
	
	qsort(A+1,cnt,sizeof(struct node),cmp);
	
	for(int i=1;i<=cnt;i++){
		printf("http://%s/%s\n",s+A[i].pos1,s+A[i].pos2);
	}
	return 0;
}