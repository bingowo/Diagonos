#include<stdio.h>
#include<stdlib.h>
struct data
	{
	    long long int a;
	    long long int number;
	};
int cmp(const void *a,const void *b)
	{
	    struct data d1,d2;
	    d1=*((struct data *)a);
	    d2=*((struct data *)b);
	    if(d2.number!=d1.number)  
	        if(d2.number>d1.number) return 1;
			else return -1;
	    else
	    {    if(d1.a>d2.a) return 1;
	         else return -1;
	    }
	}
int main()
{
	int t;
	long long int n,b[10],a[10][10000];
	scanf("%d",&t);
	struct data p[10000];
	for(int i=0;i<t;i++)
	{
		int x=i;
		scanf("%lld",&n);
		b[i]=n;
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
		a[x][n]='\0';
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n",i);
		int j=0,k=0;
		while(a[i][j]!='\0'&&k<b[i])
		{
			printf("%lld ",a[i][j]);j++;k++;
		}
		while(k<b[i])
		{
			printf("0 ");k++;
		}
		printf("\n");
		
	}
	
	
	
	return 0;
	
	
 } 