#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int ge(long long l)
{		long long t;
      if(l<0) l=-l;
	do{
		t=l;
		l=l/10;
	}while(l);
	return t;
}
int cmp(const void*a,const void *b)
{   long long aa=*(long long*)a;
	long long bb=*(long long*)b;
	if(ge(aa)!=ge(bb)) return ge(bb)-ge(aa); 
	else{
		if(aa>bb) return 1;
		else return -1;
	}
}
 int main()
 {  int k,T,N;
 	scanf("%d\n",&T);
	 for(k=0;k<T;k++)
	 {  int i=0;
	 	long long *p;
	 	scanf("%d\n",&N);
	 	p=(long long*)malloc(N*sizeof(long long));
	 	for(i=0;i<N;i++)
	 	scanf("%lld",&p[i]);
	 	qsort(p,N,sizeof(long long),cmp);
	 	printf("case #%d:\n",k);
	 	for(i=0;i<N-1;i++) printf("%lld ",p[i]);
	    printf("%lld\n",p[i]);
	 } 
		return 0;
}