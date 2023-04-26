#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include<string.h>
struct stu 
{
	char a[100];
};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	return strcmp(A->a,B->a);
}
int main()
{
	int t,i=0,b[500];
	char a[501];
	struct stu x[500];
	struct stu *p=x;
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
		gets(a);
		int j=0,k=0,g=0;
		for(int u=0;u<500;u++)
		{
			for(int y=0;y<100;y++)
			{
				x[u].a[y]=0;
			}
		}
		while(a[j]!='\0')
		{
			if(a[j]>='a'&&a[j]<='z')
			{
				x[k].a[g]=a[j];
				g++;j++;
			}
			else
			{
				k++;g=0;j++;
			}
		}
		qsort(p,k,sizeof(struct stu),cmp);
		b[0]=0;
		int f=1;
		for(int o=1;o<k+1;o++)
		{
			int e=0;
			while(x[o].a[e]!=0)
			{
				if(x[o].a[e]==x[o-1].a[e])
				{
					e++;
				}
				else
				{
					b[f]=o;f++;break;
				}
			}
		}
		printf("case #%d:\n",i);
		for(int o=0;o<f;o++)
		{
			
			printf("%s ",x[b[o]].a);
		}
		printf("\n");
		
	}

	
	
	
	
	return 0;
	
	
 } 