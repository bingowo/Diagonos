#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<malloc.h>
typedef struct{
	char s1[305],s2[305];
}STR;
STR a[101];
int cmp(const void* a,const void* b)
{
	STR x=*(STR*)a;STR y=*(STR*)b;
	if(strcmp(x.s1,y.s1)==0)
	return strcmp(x.s2,y.s2);
	return strcmp(x.s1,y.s1);
}
int main()
{
	int n,cnt=0;char ori[305];
	scanf("%d",&n);//数据其实很水
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ori);
		if(ori[4]==':')
		{
			int j=7;++cnt;int l1=7,l2=0;
			strcpy(a[cnt].s1,"http://");
			while(ori[j]!='/')a[cnt].s1[l1++]=ori[j++];
			j++;
			while(ori[j]!=0)a[cnt].s2[l2++]=ori[j++];
			a[cnt].s1[l1]=0;a[cnt].s2[l2]=0;
		}
	}
	qsort(a+1,cnt,sizeof(STR),cmp);
	for(int i=1;i<=cnt;i++)printf("%s/%s\n",a[i].s1,a[i].s2);
	return 0;
}