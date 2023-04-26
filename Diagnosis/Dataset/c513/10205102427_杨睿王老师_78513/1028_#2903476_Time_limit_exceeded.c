#include <stdio.h>
#include <stdlib.h>
int cmp1(const void * a,const void * b){
	return *(int *) a- *(int *)b;
}
int cmp2(const void * a,const void * b){
	return *(int *) b- *(int *)a;
}
int main(){
	char mode;
	scanf("%c",&mode);
	int n[101];
	int l=0;
	while(scanf("%d",&n[l])){
		l++;
	}
	if(mode=='A')qsort (n,l,sizeof(int),cmp1);
	if(mode=='D')qsort (n,l,sizeof(int),cmp2);
	printf("%d",n[0]);
	for(int y=1;y<l;y++){
		if(n[y]!=n[y-1]) printf(" %d",n[y]);
	}
}