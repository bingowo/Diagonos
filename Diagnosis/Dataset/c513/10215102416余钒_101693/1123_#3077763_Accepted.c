#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LL long long
int n; 
struct node{
	char s[25];
	int cnt;
}A[200005],B[200005];
int cmp1(const void* a,const void* b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	return strcmp(x.s,y.s);
}
int cmp2(const void* a,const void* b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	if(x.cnt!=y.cnt) return x.cnt-y.cnt;
	return strcmp(x.s,y.s);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",A[i].s);
		A[i].cnt=1;
	}
	qsort(A+1,n,sizeof(A[1]),cmp1);
	int pos=0;
	for(int i=1;i<=n;i++){
	//	printf("%s\n",A[i].s);
		if(pos==0) B[++pos]=A[i];
		else{
			if(strcmp(B[pos].s,A[i].s)!=0) B[++pos]=A[i];
			else B[pos].cnt++;
		} 
	}
	qsort(B+1,pos,sizeof(B[1]),cmp2);
	for(int i=1;i<=pos;i++) printf("%s\n",B[i].s);
	return 0;
}