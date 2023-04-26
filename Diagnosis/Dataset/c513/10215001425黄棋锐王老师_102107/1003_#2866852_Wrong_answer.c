#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long yi(long long x){
	long long n=0,i;
	 for(i=0;i<64;i++){
	 	if(x&01!=0) n++;
		 x=x>>1; 
	 }
	 return n;
}
long long cmp(const void*a,const void*b){
	long long aa;
	long long bb;
	aa=*(long long*)a;
	bb=*(long long*)b;
	if(yi(aa)!=yi(bb)) return yi(bb)-yi(aa);
	else if(yi(aa)==yi(bb)) return aa-bb;
}

int main(int argc, char *argv[]) {
	int T,i,d,j; 
	 long long a[20000];
	scanf("%d\n",&T);
	for(i=0;i<T;i++){
		scanf("%d",&d);
		for(j=0;j<d;j++) scanf("%ld",&a[j]);
		printf("case #%d:\n",i);
		qsort(a,d,sizeof(long long),cmp);
		for (j=0;j<d;j++) printf("%ld%c",a[j],j!=d-1?' ':'\n');
	}
	
	return 0;
}