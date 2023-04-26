#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b){
	long long aa=*(long long*)a;
	long long bb=*(long long*)b;
	if(bb>aa) return 1;
	else return -1; 
}
 int main()
 {    int n,m;
 	scanf("%d %d",&n,&m);
	 long long *a;
	 long long d;
	 long long *c;
	 a=(long long*)malloc(n*sizeof(long long));
	 c=(long long*)malloc(n*sizeof(long long));
	 int i;
	 for(i=0;i<n;i++) {
	 scanf("%lld",&a[i]);
	 c[i]=0;
	 }
	 qsort(a,n,sizeof(long long),cmp);
	 for(i=0;i<m-1;i++) d+=a[i];
	 int j;
	 c[0]=(m-1)*a[m-1]-d;
	for(j=1;j<=n-m+1;j++){
		c[j]=c[j-1]+a[j-1]-m*a[j+m];
	}
	 qsort(c,n-m+1,sizeof(long long),cmp);
	 printf("%lld",c[0]);
	 free(a);free(c);
		return 0;
}