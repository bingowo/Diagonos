#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long long int id;
	int score;
}stu;
int cmp(const void *p1,const void *p2){
	stu a=*((stu*)p1),b=*((stu*)p2);
	if (a.score!=b.score){
		return b.score-a.score;
	}
	else{
		if(a.id>b.id) return 1;
		else return -1;
	}
}
int main(int argc, char *argv[]) {
	int t,cas;
	scanf("%d",&t);
	for(cas=0;cas<t;cas++){
		int n,m,g,i,j,qn,pstu=0;
		scanf("%d %d %d",&n,&m,&g);
		stu l[500];
		int ql[10];
		int scorel[10];
		for(i=1;i<=m;i++){
			scanf("%d",&scorel[i]);
		}
		for(i=0;i<n;i++){
			scanf("%llu %d",&l[i].id,&qn);
			l[i].score=0;
			for(j=0;j<qn;j++){
				scanf("%d",&ql[j]);
				l[i].score+=scorel[ql[j]];
			}
			if(l[i].score>=g){
				pstu+=1;
			}
		}
		qsort(l,n,sizeof(l[0]),cmp);
		printf("case #%d:\n%d\n",cas,pstu);
		for(i=0;i<pstu;i++){
			printf("%10.llu %d\n",l[i].id,l[i].score);
		}
	}
	return 0;
}