#include<stdio.h>
#include<math.h>
#include<string.h>
struct stu
	{
		double rou;
		double o;
	};
int cmp(const void *a,const void *b)
{
	struct stu* A=(struct stu*)a;
	struct stu* B=(struct stu*)b;
	if(A->o!=B->o) return((A->o)-(B->o))*1000;
	else
	{
		return((B->rou)-(A->rou))*1000;
	}
}
int main()
{
	int t,n,d[10];
	double x,y,b[10][1000][2];
	struct stu a[1000];
	struct stu *p=a;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);d[i]=n;
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&x,&y);
			(p+i)->rou=sqrt(x*x+y*y);
			if(atan2(y,x)>=0)
			{
				(p+i)->o=atan2(y,x);
			}
			else
			{
				(p+i)->o=atan2(y,x)+6.283185;
			}
		}
		qsort(p,n,sizeof(struct stu),cmp);
		for(int j=0;j<n;j++)
		{
			b[i][j][0]=(p+j)->rou;
			b[i][j][1]=(p+j)->o;
		}
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n",i);
		for(int j=0;j<d[i];j++)
		{
			printf("(%.4f,%.4f)\n",b[i][j][0],b[i][j][1]);
		}
	}
	
	
	

	
	return 0;
	
	
 } 