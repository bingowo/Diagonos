#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 int cmp(const void*a,const void*b)
 	{   long long aa=*(long long*)a;
 		long long bb=*(long long*)b;
 		if(aa>bb) return 1;
 		else return -1;
 	}
 	
 int main()
 {  int n,i;
    scanf("%d",&n);
	long long*p;
	p=(long long*)malloc(n*sizeof(long long));//*******
	for(i=0;i<n;i++) scanf("%lld",p+i); 
	qsort(p,n,sizeof(long long ),cmp);
	long long min=0;
	for(i=1;i<n;i+=2)
	 	min+=p[i]-p[i-1];
	 free(p);
	printf("%lld",min);
		return 0;
}