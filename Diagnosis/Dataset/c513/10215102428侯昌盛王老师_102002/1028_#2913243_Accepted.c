#include <stdio.h>
#include <stdlib.h>

int cmp1(const void*a,const void*b)
{
	int *q,*p;
	q=(int*)a;p=(int*)b;
	return *q-*p;
}

int cmp2(const void*a,const void*b)
{
	int *q,*p;
	q=(int*)a;p=(int*)b;
	return *p-*q;
}

int main()
{
	char x;
	scanf("%c",&x);
	int a[100],i=0,m,n=0;
	do{
		scanf("%d",&m);
		int j=0;
		//printf("%d\n",a[i]);
		for(j;j<i;j++)
		{
			if(a[j]==m) break;
			
		}
		if(i==j) {a[i]=m;n++;i++;}
	
		
	}while(getchar()==' ');
//	printf("%d\n",a[1]);
	if(x=='A') qsort(a,n,sizeof(a[0]),cmp1);
	else qsort(a,n,sizeof(a[0]),cmp2);
	int j=0;
	for(j;j<n;j++) printf("%d ",a[j]);
	return 0; 
	
}