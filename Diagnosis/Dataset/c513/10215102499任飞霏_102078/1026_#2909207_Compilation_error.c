#include <stdio.h>
#include <stdlib.h>

int cmp(const void* m;const void* n)
{
	int x = *(int *)m;
	int y = *(int *)n;
	return m-n;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[1000];
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	int ans = 0;
	for(int i = 0;i < n;i+=2){
		ans = ans + a[i+1] - a[i];
	}
	printf("%d",ans);
	return 0;
}