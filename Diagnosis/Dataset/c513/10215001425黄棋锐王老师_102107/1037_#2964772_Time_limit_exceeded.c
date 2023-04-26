#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b){
	long long aa=*(long long*)a;
	long long bb=*(long long*)b;
	if(aa>bb) return 1;
	else return -1;
}
 int main()
 {    int n,m;
 	scanf("%d %d",&n,&m);
	 long long *a;
	 long long *b;
	 a=(long long*)malloc(n*sizeof(long long));
	 b=(long long*)malloc(n*sizeof(long long));
	 int i;
	 for(i=0;i<n;i++) {
	 scanf("%lld",&a[i]);
	 b[i]=0;
	 }
	 qsort(a,n,sizeof(long long),cmp);
	 i=0;
	 int j=0,p;
	do{  int t=i+m-1;
		for(p=i;p<t;p++){
			b[j]+=a[t]-a[p];
		}
		  i++;
		  j++;
	}while(i<=n-m);
	 qsort(b,n-m+1,sizeof(long long),cmp);
	 printf("%lld",b[0]);
	 free(a);free(b);
		return 0;
}