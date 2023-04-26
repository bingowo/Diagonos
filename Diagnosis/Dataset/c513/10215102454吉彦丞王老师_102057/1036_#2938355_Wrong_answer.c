#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct data
{
    long long int x;
    long long int y;
    unsigned long long r;
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
unsigned long long dx(struct data p1,struct data p2)
{
    return llabs(p1.x-p2.x);
}
unsigned long long dy(struct data p1,struct data p2)
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
	while(zhishu(t)<=n/2)
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
            if(a.y>b.y)
            {
            	return 1;
			}
			else
			{
				return -1;
			}
        }
        else
        {
            if(a.x>b.x)
            {
            	return 1;
			}
			else
			{
				return -1;
			}
        }
    }
    else
    {
        if(b.r>a.r)
        {
        	return 1;
		}
		else
		{
			return -1;
		}
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
    printf("%llu\n",dx(p[0],p[1])+dy(p[0],p[1]));
    int t=0;
    for(int i=0;i<number-1;i++)
    {
    	if(dx(p[i],p[i+1])*dy(p[i],p[i+1])==0)
    	{
    		long long int f=zhishu(fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1])))-1-dx(p[i],p[i+1])-dy(p[i],p[i+1])+zhishu(fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1])));
        	while(f>0)
        	{
        		f=f-max(zhishu(fuck(f)),2);
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
        	if((dx(p[i],p[i+1])%2==0&&dy(p[i],p[i+1])%2==1)||(dx(p[i],p[i+1])%2==1&&dy(p[i],p[i+1])%2==0))
        	{
        		long long int f=zhishu(fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1])))-1-dx(p[i],p[i+1])-dy(p[i],p[i+1])+zhishu(fuck(dx(p[i],p[i+1])+dy(p[i],p[i+1])));
        		while(f>0)
        		{
        			f=f-max(zhishu(fuck(f)),2);
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