#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m; 
char s[1005];
struct node{
	char t1[30],t2[30],name[70];
	long long size;
}A[1005];
int cmp1(const void * a, const void * b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	if(strcmp(x.t1,y.t1)!=0) return strcmp(x.t1,y.t1);
	else if(strcmp(x.t2,y.t2)!=0) return strcmp(x.t2,y.t2);
	else return strcmp(x.name,y.name);
}
int cmp2(const void * a, const void * b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	if(x.size!=y.size) return x.size-y.size;
	else return strcmp(x.name,y.name);
}
int cmp3(const void * a, const void * b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	return strcmp(x.name,y.name);
}
int main() {
	while(~scanf("%d",&n)){
		if(n==0) break;
		for(int i=1;i<=n;i++)
			scanf("%s%s%lld%s\n",A[i].t1,A[i].t2,&A[i].size,A[i].name);
		gets(s);
		if(s[6]=='T') qsort(A+1,n,sizeof(struct node),cmp1);
		else if(s[6]=='S') qsort(A+1,n,sizeof(struct node),cmp2);
		else qsort(A+1,n,sizeof(struct node),cmp3);
		for(int i=1;i<=n;i++)
			printf("%s %s%17lld %s\n",A[i].t1,A[i].t2,A[i].size,A[i].name);
		puts("");
	}
	return 0;
}