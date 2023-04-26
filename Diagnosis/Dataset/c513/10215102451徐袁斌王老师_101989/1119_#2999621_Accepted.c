#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int d,n,k,s,a,b;
    scanf("%d",&d);
    scanf("%d",&n);
    scanf("%d %d",&k,&s);
	double ans=0;
	ans=d/((d-k)*1.0/s);
    for(int i=1;i<n;i++)
    {
		scanf("%d%d",&a,&b);
		if(d/((d-a)*1.0/b)<ans) ans=d/((d-a)*1.0/b);
	}
	printf("%.6f",ans);
}