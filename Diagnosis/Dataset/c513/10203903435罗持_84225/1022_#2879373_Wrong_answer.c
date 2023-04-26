#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	char name[200];
	char zhu[200];
}a[1000010];
int mycmp(const void* xx,const void* yy)
{
	struct node x = *((struct node*)xx);
	struct node y = *((struct node*)yy);
	if(strcmp(x.zhu,y.zhu)==0) return strcmp(y.name,x.name);
	return strcmp(x.zhu,y.zhu);
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s@%s",&a[i].name,&a[i].zhu);
	qsort(a+1,n,sizeof(a[0]),mycmp);
	for(int i=1;i<=n;i++)
		printf("%s@%s\n",a[i].name,a[i].zhu);
	return 0;
}