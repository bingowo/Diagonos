#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m,G,T; 
int w[105];
struct node{
	char id[20];
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
		scanf("%d%d%d",&n,&m,&G);
		for(int i=1;i<=m;i++)
			scanf("%d",&w[i]);
		int cnt=0;
		for(int i=1;i<=n;i++){
			A[i].val=0;
			int tot,x;
			scanf("%s%d",A[i].id,&tot);
			for(int j=1;j<=tot;j++) 
				scanf("%d",&x),A[i].val+=w[x];
			if(A[i].val>=G) cnt++;
		}
		qsort(A+1,n,sizeof(struct node),cmp);
		printf("case #%d:\n%d\n",c,cnt);
		for(int i=1;i<=cnt;i++)
			printf("%s %d\n",A[i].id,A[i].val);
	}
	return 0;
}