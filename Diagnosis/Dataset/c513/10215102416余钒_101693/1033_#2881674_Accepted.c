#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int T,n;
char s[20][20]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

struct node{
	int y,m,d;
}A[10005];

int cmp(const void* a,const void* b){
	struct node x=*(struct node*)a,y=*(struct node*)b;
	if(x.y!=y.y) return x.y-y.y;
	else if(x.m!=y.m) return x.m-y.m;
	else return x.d-y.d;
}
int main() {
	scanf("%d",&T);
	for(int c=0;c<T;c++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int day,year;
			char m[20];
			scanf("%d. %s %d",&day,m,&year);
			for(int j=0;j<19;j++)
				if(strcmp(m,s[j])==0){
					A[i].d=day,A[i].m=j,A[i].y=year;
					break;
				}
		}
		qsort(A+1,n,sizeof(struct node),cmp);
		printf("case #%d:\n",c);
		for(int i=1;i<=n;i++)
			printf("%d. %s %d\n",A[i].d,s[A[i].m],A[i].y);
	}
	return 0;
}