#include<stdio.h>
#include<stdilb.h>
int tongji(int x)
{
    int i=0;
    if(x<0)
        x=x*-1;
    for(;x>0;i++)
    {
        x=x/10;
    }
    return i; 
}
int comp(const void*p1,const void*p2)
{
     int x;
     int n1,n2;
    n1=*( int*)p1;
    n2=*( int*)p2;
    x=tongji(n1)-tongji(n2);
    if(x!=0)
    {
        return -x;
    }
    else
    {
        if((n1-n2)<0)
            x=-1;
        else
            x=1;
        return x;
    }
}
int main()
{
    int a[100000],n,m;
    int i=0;
	while(scanf("%d",&n)==1)
	{
		a[i]=n;
		i++;
	
	}
	qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),cmp);
	for(int z=0;z<--i;i++)
	{
	    printf("%d",a[z]);
	}
	
}
