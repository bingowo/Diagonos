#include<stdio.h>
#include<math.h>
#include<string.h>
struct stu
	{
		long long int x;
		int y;
		
	};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	
	if(A->y!=B->y) return(B->y-A->y);
	else
	{
		if(A->x>B->x) return 1;
		else return -1;
	}
	
}
int main()
{
	int t,n,c[10];
	long long int b,d[10][10000];
	struct stu a[10000];
	struct stu *p=a;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);c[i]=n;
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&b);
			(p+j)->x=b;
			while(abs(b)>=10)
			{
				b=b/10;
			}
			(p+j)->y=abs(b);
		}
		qsort(p,n,sizeof(struct stu),cmp);
		for(int k=0;k<n;k++)
		{
			d[i][k]=(p+k)->x;
		}
		
	}
	
	
	
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n",i);
		printf("%lld",d[i][0]);
		for(int j=1;j<c[i];j++)
		{
			printf(" %lld",d[i][j]);
		}
		printf("\n");
	}
	
	
	
	

	
	return 0;
	
	
 } 