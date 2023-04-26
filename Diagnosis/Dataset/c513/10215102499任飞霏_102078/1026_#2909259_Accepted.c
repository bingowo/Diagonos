#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b);

int main()
{
	int n;
	scanf("%d",&n);
	int s[10003986];
	for(int i = 0;i < n;i++){
		scanf("%d",&s[i]);
	}
	qsort(s,n,sizeof(int),cmp);
	int ans = 0;
	for(int i = 0;i < n;i+=2){
		ans = ans + s[i+1] - s[i];
	}
	printf("%d",ans);
	return 0;
}

int cmp(const void* a,const void* b)
{
    int x = *((int *)a);
    int y = *((int *)b);
    return x-y;
}
