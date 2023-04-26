#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n;
char s[105];
struct node{
	int top;
	long long val;
}A[100005];
int cmp(const void* a,const void* b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	if(x.top!=y.top) return y.top-x.top;
	else if(x.val>y.val) return 1;
	else return -1;
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			for(int j=0;s[j];j++)
				if(s[j]>='0'&&s[j]<='9'){
					A[i].top=s[j]-'0';
					break;
				}
			A[i].val=atoll(s);
		}
		qsort(A+1,n,sizeof(struct node),cmp);
		printf("case #%d:\n",c);
		for(int i=1;i<=n;i++) printf("%lld ",A[i].val);
		puts("");
	}
	return 0;
}