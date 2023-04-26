#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct data
{
    long long int x;
    long long int y;
    long long int r;
};
long long int max(long long int a,long long int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
long long int dx(struct data p1,struct data p2)
{
    return llabs(p1.x-p2.x);
}
long long int dy(struct data p1,struct data p2)
{
    return llabs(p1.y-p2.y);
}
long long int zhishu(int n)
{
	long long int t=1;
	for(int i=0;i<n;i++)
	{
		t=t*2;
	}
	return t;
}
int fuck(long long int n)
{
	int t=0;
	while(zhishu(t)<n/2+1)
	{
		t++;
	}
	return t;
}
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    if(a.r==b.r)
    {
        if(a.x==b.x)
        {
            return a.y-b.y;
        }
        else
        {
            return a.x-b.x;
        }
    }
    else
    {
        return b.r-a.r;
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    struct data p[number];
    for(int i=0;i<number;i++)
    {
        scanf("%lld",&p[i].x);
        scanf("%lld",&p[i].y);
        p[i].r=fabs(p[i].x)+fabs(p[i].y);
    }
    qsort(p,number,sizeof(p[0]),cmp);
    printf("%lld\n",dx(p[0],p[1])+dy(p[0],p[1]));
    int t=0;
    for(int i=0;i<number;i++)
    {
    	if(dx(p[i],p[i+1])*dy(p[i],p[i+1])==0)
    	{
    		long long int f=zhishu(fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1])))-1-dx(p[i],p[i+1])-dy(p[i],p[i+1])+zhishu(fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1])));
        	while(f>0)
        	{
        		f=f-max(zhishu(fuck(f)-1),2);
			}
			if(f==0)
			{
				t=t+fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1]))+1;
			}
			else
			{
				break;
			}
		}
		else
        {
        	if(dx(p[i],p[i+1])%2==0&&dy(p[i],p[i+1])%2==1||dx(p[i],p[i+1])%2==1&&dy(p[i],p[i+1])%2==0)
        	{
        		long long int f=zhishu(fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1])))-1-dx(p[i],p[i+1])-dy(p[i],p[i+1])+zhishu(fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1])));
        		while(f>0)
        		{
        			f=f-max(zhishu(fuck(f)-1),2);
				}
				if(f==0)
				{
					t=t+fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1]))+1;
				}
				else
				{
					break;
				}
			
        	}
        	else
        	{
        		break;
			}
		}
    }
    printf("%d",t);
    return 0;
}