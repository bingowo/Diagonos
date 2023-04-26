#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	char time1[30];
	char time2[30];
	int bit;
	char name[70];
}a[111];
int mycmp1(const void* xx, const void* yy)
{
	struct node x = *((struct node*)xx);
	struct node y = *((struct node*)yy);
	return strcmp(x.name,y.name);
}
int mycmp2(const void* xx, const void* yy)
{
	struct node x = *((struct node*)xx);
	struct node y = *((struct node*)yy);
	if(x.bit == y.bit) return strcmp(x.name,y.name);
	return x.bit > y.bit;
}
int mycmp3(const void* xx, const void* yy)
{
	struct node x = *((struct node*)xx);
	struct node y = *((struct node*)yy);
	if(strcmp(x.time1,y.time1)==0)
	{
		if(strcmp(x.time2,y.time2)==0) return strcmp(x.name,y.name);
		return strcmp(x.time2,y.time2);
	}
	return strcmp(x.time1,y.time1);
}
int main(void)
{
	int n;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		for(int i=1;i<=n;i++)
		{
			scanf("%s %s %d %s",&a[i].time1,&a[i].time2,&a[i].bit,&a[i].name); 
		}
		char nouse[20];
		scanf("%s",nouse);
		char ml[20];
		scanf("%s",ml);
		if(ml[1]=='N') qsort(a+1,n,sizeof(a[0]),mycmp1);
		if(ml[1]=='S') qsort(a+1,n,sizeof(a[0]),mycmp2);
		if(ml[1]=='T') qsort(a+1,n,sizeof(a[0]),mycmp3);
		for(int i=1;i<=n;i++)
			printf("%s %s %16d %s\n",a[i].time1,a[i].time2,a[i].bit,a[i].name);
		putchar('\n');
	}
	return 0;
}