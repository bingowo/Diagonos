#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stu
{
	int a;
	int b;
};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(A->b==B->b) return A->a-B->a;
	else return A->b-B->b;
}	
int main()
{
	int m,n,a[500];
	struct stu x[500];
	struct stu *p=x;
	scanf("%d",&m);
	for(int i=0;i<m;i++) {scanf("%d",&a[i]);}
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i].a);
		for(int j=0;j<m+1;j++)
		{
			if(j==m) x[i].b=m;
			else
			{
				if(x[i].a==a[j]) {x[i].b=j;break;}
			}
		}
	}
	qsort(p,n,sizeof(x[0]),cmp);
	for(int i=0;i<n;i++)
	{
		printf("%d ",x[i].a);
	}
	return 0;
 } 