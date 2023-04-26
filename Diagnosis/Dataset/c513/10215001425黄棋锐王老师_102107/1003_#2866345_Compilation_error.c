#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yi(int x){
	int n=0,i;
	 for(i=0;i<64;i++){
	 	if(x&01!=0) n++;
		 x>>1; 
	 }
	 return n;
}
int cmp(const void*a,const void*b){
	int aa;
	int bb;
	aa=*(int*)a;
	bb=*(int*)b;
	if(yi(aa)!=yi(bb)) return yi(bb)-yi(aa);
	else if(yi(aa)==yi(bb)) return aa-bb;
}

int main(int argc, char *argv[]) {
	int T,i,d; 
	int a[20000];
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
		scanf("%d",&d);
		for(j=0;j<d;j++) scanf("%d",a[j]);
		printf("case #%d:\n",i);
		qsort(a,d,sizeof(int),cmp);
		for (j=0;j<d;j++) printf("%d%c",a[j],j!=n-1?' ':'\n');
	}
	
	return 0;
}
