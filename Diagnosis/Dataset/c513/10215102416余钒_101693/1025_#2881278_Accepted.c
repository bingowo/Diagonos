#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,T; 
int w[105],cnt[100];
struct node{
	char id[25];
	int val;
}A[5005];

int cmp(const void* a,const void* b){
	struct node x=*(struct node *)a,y=*(struct node *)b;
	if(x.val!=y.val) return y.val-x.val;
	else return strcmp(x.id,y.id);
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",A[i].id);
			A[i].val=0;
			for(int j=0;j<26;j++) cnt[j]=0;
			for(int j=0;A[i].id[j];j++){
				cnt[A[i].id[j]-'A']++;
				if(cnt[A[i].id[j]-'A']==1) A[i].val++;
			}
		}
		qsort(A+1,n,sizeof(struct node),cmp);
		printf("case #%d:\n",c);
		for(int i=1;i<=n;i++)
			printf("%s\n",A[i].id);
	}
	return 0;
}