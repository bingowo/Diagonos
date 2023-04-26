#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int d,n,k,s,a,b;
    scanf("%d",&d);
    scanf("%d",&n);
    scanf("%d %d",&k,&s);
    for(int i=1;i<n;i++)
    {
		scanf("%d%d",&a,&b);
		if(b<s)
		{
			k=a;s=b;
		}
		else if(b==s)
		{
			if(a<k) k=a;
		}
	}
	double ans=0;
	ans=d/((d-k)*1.0/s);
	printf("%.6f",ans);
}