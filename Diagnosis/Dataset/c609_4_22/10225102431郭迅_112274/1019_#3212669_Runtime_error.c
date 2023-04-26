#include<stdio.h>
#define N 1000000
int cmp(const void*a,const void*b)
{
	int aa=*(int*)a;
	int bb=*(int*)b;
	if(aa<0)aa=abs(aa);
	if(bb<0)bb=abs(bb);
	int c=(int)log10(aa);
	int d=(int)log10(bb);
	if(c!=d){return d-c;
	}
	else{return *(int*)a-*(int*)b;
	}
}
int main()
{
	int a[N],i=0;
	while(scanf("%d",&a[i])!=EOF){i++;
	}
	qsort(a[N],i,sizeof(int),cmp);
	for(int j=0;j<i;j++){
		printf("%d",a[j]);
	}
 } 