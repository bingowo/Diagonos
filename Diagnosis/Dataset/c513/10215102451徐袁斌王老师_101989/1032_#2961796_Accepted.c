#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
	{
		int a[51];
		int b;
	};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	int i=0;
	if(A->a[i]!=B->a[i]){return B->a[i]-A->a[i];}
	else
	{
		while(A->a[i]==B->a[i])
		{
			if(A->b==i) return 1;
			else if(B->b==i) return -1;
			else{i++;}
		}
		return B->a[i]-A->a[i];
	}
}
int main()
{
	int t,d,a;
	scanf("%d",&t);
	struct stu x[1000];
	struct stu *p=x;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&d);
		for(int j=0;j<1000;j++)
		{
			for(int k=0;k<51;k++)
			{
				x[j].a[k]=-1;
			}
		}
		for(int j=0,k=0;j!=d||a!=-1;k++)
		{
			scanf("%d",&a);
			if(a!=-1){x[j].a[k]=a;x[j].b=k;}
			else{j++;k=-1;}
		}
		qsort(p,d,sizeof(struct stu),cmp);
		for(int j=0,k=0;j<d;j++)
		{
			while(x[j].a[k]!=-1)
			{
				printf("%d ",x[j].a[k]);
				k++;
			}
			printf("\n");k=0;
		}
		
		
	}
	
}