#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
	{
		char a[20];
		int b;
	};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(A->b==B->b)
	{
		return strcmp(A->a,B->a);
	}
	else
	{
		return B->b-A->b;
	}
}
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		struct stu x[100];
		struct stu *p=x;
		for(int j=0;j<n;j++)
		{
			scanf("%s",x[j].a);x[j].b=0;
			int k=0,a[128]={0};
			while(x[j].a[k]!='\0')
			{
				if(a[x[j].a[k]]==0){x[j].b++;a[x[j].a[k]]++;}
				k++;
			}
			
		}
		qsort(p,n,sizeof(x[0]),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<n;j++)
		{
			printf("%s\n",x[j].a);
		}
		
		
		
	}
}
