#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
int cmp2(const void *a,const void *b){
	return *(int *)b-*(int *)a;
}
int main(){
	int n,i=0,j,a[200],(*cmp)(const void *,const void *);
	char c;
	scanf("%c",&c);
	if(c=='A') cmp=cmp1;
	else cmp=cmp2;
	while(scanf("%d",&a[i])!=EOF) ++i;
	qsort(a,i-1,sizeof(a[0]),cmp);
	for(j=0;j<i;++j){
		if(j&&a[j]==a[j-1]) continue;
		printf("%d ",a[j]);
	}
	return 0;
} 