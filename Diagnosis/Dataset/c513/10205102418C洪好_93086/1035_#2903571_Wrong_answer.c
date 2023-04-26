#include<stdio.h>
#include<stdlib.h> 

typedef struct 
{
	int r;
	int h;
	long long b;
}node; 

int cmpb(const void*q1,const void*q2)
{
	node *t1=(node*) q1;
	node *t2=(node*) q2;
	if(t1->b==t2->b)
	{
		return ( t2->r-t1->r );
	}
	return ( t2->b-t1->b );
}

int cmpd(const void*q1,const void*q2)
{
	node *t1=(node*) q1;
	node *t2=(node*) q2;
	if(t1->r==t2->r)
	{
		return ( t1->b-t2->b );
	}
	return ( t1->r-t2->r );
}

int main()
{
	int n,m;  //n个圆柱选m个 
	scanf("%d %d",&n,&m);
	node yz[1000]; 
	int r,h;
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&yz[i].r,&yz[i].h);
		yz[i].b=yz[i].r*2*yz[i].h;
	}
	qsort(yz,n,sizeof(yz[0]),cmpd);
	node new[1000];
	long long res=0,x;
	for(i=m-1;i<n;i++)
	{
		x=yz[i].r*yz[i].r+yz[i].b;
		for(j=0;j<i;j++)
		{
			new[j]=yz[j];
		}
		qsort(new,i,sizeof(new[0]),cmpb);
		for(j=0;j<m-1;j++)
			x+=new[j].b;
    	if(x>res)   res=x;
	}
	printf("%lld\n",res);
	return 0;
}