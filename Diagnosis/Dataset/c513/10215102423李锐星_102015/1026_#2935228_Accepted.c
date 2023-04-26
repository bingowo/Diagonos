#include <stdio.h>
#include <stdlib.h>
int a[100000];

int cmp(const void *a,const void *b)
{
	int x,y;
	x=*(int*)a;
	y=*(int*)b;
	if (x<y){
		return -1;
	}
	else{
		return 1;
	}
}
int main()
{
	int n,i,j=0;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&a[i]); 
	}
	qsort(a,n,sizeof(a[0]),cmp);
	int sum=0;
	for (i=0;i<n/2;i++){
		if (a[j+1]-a[j]>=0){
			sum+=a[j+1]-a[j];
		}
		else{
			sum-=a[j+1]-a[j];
		}
		j+=2;
	}
	printf("%d\n",sum);
	return 0;
}