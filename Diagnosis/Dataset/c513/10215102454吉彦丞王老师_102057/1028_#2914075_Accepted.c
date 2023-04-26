#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}
int cmp2(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return b-a;
}
int main()
{
    char x,h;
    scanf("%c",&x);
    int a[100];
    int b[100];
    int l=0;
    int t=1;
    for(int i=0;h!='\n';i++)
    {
        scanf("%d",&a[i]);
        h=getchar();
        l++;
    }
    qsort(a,l,sizeof(int),cmp1);
    b[0]=a[0];
    for(int j=0;j<l-1;j++)
    {
    	if(a[j]!=a[j+1])
    	{
    		b[t]=a[j+1];
    		t=t+1;
		}
	}
	if(x=='A')
	{
		qsort(b,t,sizeof(int),cmp1);
	}
	else
	{
		qsort(b,t,sizeof(int),cmp2);
	}
    for(int k=0;k<t-1;k++)
    {
    	printf("%d ",b[k]);
	}
	printf("%d",b[t-1]);
}