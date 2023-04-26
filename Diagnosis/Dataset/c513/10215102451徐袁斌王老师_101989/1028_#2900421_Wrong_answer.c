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
	int* A=(int *)a;
	int* B=(int*)b;
	return *A-*B;
}
int main()
{
	int a[100],x,i=0;
	char t;
	int *p=a;
	scanf("%c",&t);
	while(scanf("%d",&x)!= EOF) 
	{
		a[i]=x;
		i++;
	}
	qsort(p,i,sizeof(int),cmp);
	
	
	
	if(t=='A')
	{
		int y=a[0];
		int j=1;
		printf("%d",a[0]);
		while(a[j]!='\0')
		{
			if(y!=a[j])
			{
				printf(" %d",a[j]);
				y=a[j];j++;
			}
			else
			{
				j++;
			}
		}
	}
	if(t=='D')
		{
			int y=a[i-1];
			int j=i-2;
			printf("%d",a[i-1]);
			while(j!=-1)
			{
				if(y!=a[j])
				{
					printf(" %d",a[j]);
					y=a[j];j--;
				}
				else
				{
					j--;
				}
			}
		}
	
	

	
	return 0;
	
	
 } 