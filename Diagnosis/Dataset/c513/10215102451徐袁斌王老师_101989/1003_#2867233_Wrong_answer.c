#include<stdio.h>
#include<stdlib.h>
struct data
	{
	    long long int a;
	    int number;
	};
int cmp(const void *a,const void *b)
	{
	    struct data d1,d2;
	    d1=*((struct data *)a);
	    d2=*((struct data *)b);
	    if(d2.number!=d1.number)  
	         return d2.number-d1.number;
	    else
	    {    if(d1.a>d2.a) return 1;
	         else return -1;
	    }
	}
int main()
{
	int t,n,a[10][10000];
	scanf("%d",&t);
	struct data p[10000];
	for(int i=0;i<t;i++)
	{
		int x=i;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{   
			scanf("%lld",&p[i].a);
		    int d=1;p[i].number=0;
		    for(int j=0;j<64;j++)
		    {
		        if(p[i].a&d) p[i].number++;
		        d=d<<1;
		    }
		}
		qsort(p,n,sizeof(p[0]),cmp);
		for(int j=0;j<n;j++)
		    a[x][j]=p[j].a;
		
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n",i);
		int j=0;
		while(a[i][j])
		{
			printf("%d ",a[i][j]);j++;
		}
		printf("\n");
		
	}
	
	
	
	return 0;
	
	
 } 