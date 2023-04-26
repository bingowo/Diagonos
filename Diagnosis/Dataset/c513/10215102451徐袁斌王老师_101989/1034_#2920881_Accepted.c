#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
{
	char a;
	double b;
	
};

int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(A->a!=B->a)
	{
		if(abs(A->a-B->a)==32)
		{
			return B->a-A->a;
		}
		else
		{
			if((A->b)-(B->b)>0){return -1;}
			else return 1;
		}
	} 
	else 
	{
		if((B->a)-(A->a)>0) return 1;
		else return -1;
	}
}
int main()
{
	int t,j;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		double a[26]={0};
		char b[101]={0};
		struct stu x[101];
		struct stu *p;
		for(int k=0;k<101;k++)
		{
			x[k].a=0;x[k].b=0;
		}
		for(int j=0;j<26;j++)
		{
			scanf("%lf",&a[j]);
		}
		scanf("%s",b);
		for(j=0;b[j]!='\0';j++)
		{
			if(b[j]>='A'&&b[j]<='Z')
			{
				x[j].a=b[j];
				x[j].b=a[b[j]-65];
			}
			else
			{
				x[j].a=b[j];
				x[j].b=a[b[j]-97];
			}
		}
		p=x;
		qsort(p,j+1,sizeof(struct stu),cmp);
		printf("case #%d:\n",i);
		int k=0;
		while(x[k].a!=0)
		{
			printf("%c",x[k].a);k++;
		}
		printf("\n");
	}

	
	
	

	
	return 0;
	
	
 } 