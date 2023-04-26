#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct data
{
    double d;
    double r;
};
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.r>b.r)
    {
        return 1;
    }
    else if(a.r<b.r)
    {
        return -1;
    }
    else
    {
        if(a.d>b.d)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int a;
        scanf("%d",&a);
        float x[a];
        float y[a];
        struct data p[a];
        for(int j=0;j<a;j++)
        {
            scanf("%f",&x[j]);
            scanf("%f",&y[j]);
            p[j].d=sqrt(x[j]*x[j]+y[j]*y[j]);
            if(y[j]>0)
            {
            	if(x[j]>0)
                {
					p[j].r=atan(y[j]/x[j]);
				}
				else if(x[j]==0)
				{
					p[j].r=3.14159265358/2;
				}
				else
				{
					p[j].r=atan(y[j]/x[j])+3.14159265358;
				}
            }
            else if(y[j]==0)
            {
            	if(x[j]>=0)
            	{
            		p[j].r=0.0000;
				}
				else
				{
					p[j].r=3.14159265358;
				}
			}
            else
            {
                if(x[j]<0)
                {
                	p[j].r=atan(y[j]/x[j])+3.14159265358;
				}
				else if(x[j]==0)
				{
					p[j].r=4.7124;
				}
				else
				{
					p[j].r=atan(y[j]/x[j])+3.14159265358*2;
				}
            }
        }
        qsort(p,a,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<a;k++)
        {
            printf("(");
            printf("%.4f",p[k].d);
            printf(",");
            printf("%.4f",p[k].r);
            printf(")\n");
        }
    }
    return 0;
}
