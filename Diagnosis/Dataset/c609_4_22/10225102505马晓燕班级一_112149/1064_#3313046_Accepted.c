#include<stdio.h>

int main()
{
	long long x,y,ans=0;
	scanf("%lld %lld",&x,&y);
	if(x%y==0)
		    ans = x*4;
	else
    {
        while(x!=0 && y!=0)
	    {
		    
		    if(x>y)
			    ans += 4*y,x-=y;
    		else if(x<y)
	    		ans += 4*x,y-=x;
		    else
			    ans += 4*x,x-=x,y-=y;
	    }
    }
	printf("%lld\n",ans);
	return 0;
}
