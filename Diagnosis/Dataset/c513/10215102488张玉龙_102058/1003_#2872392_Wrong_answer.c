#include <stdio.h>
#include <stdlib.h>
 
int cmp(const void *a, const void *b)
{
	long int anum = *(long int *)a;
	long int bnum = *(long int *)b;
	long int acnt, bcnt;
	acnt = bcnt = 0;
	while(anum > 0){
		if(anum % 2 == 1){
			acnt ++;
		}
		anum /= 2;
	}
	while(bnum > 0){
		if(bnum % 2 == 1){
			bcnt ++;
		}
		bnum /= 2;
	}
	if(acnt != bcnt){
		return bcnt - acnt;
	}else{
		return *(long int *)a > *(long int *)b ? 1 : -1;
	}
}

void Sort(long *p, unsigned n)
{
	qsort(p, n, sizeof(long), cmp);
}

int main()
{ 
	unsigned n1,n[10],i,j;
	long a[10][1000];  	
	scanf("%u",&n1);
	for(j=0;j<n1;j++){
		scanf("%u",&n[j]);
		for (i=0;i<n[j];i++)
			scanf("%ld",&a[j][i]);
			Sort(a[j],n[j]);
	}
	for(j=0;j<n1;j++){
		printf("case #%d:\n",j);
		for (i=0;i<n[j];i++)
		printf("%ld%c",a[j][i],i!=n[j]-1?' ':'\n');
  	}
	return 0;
}