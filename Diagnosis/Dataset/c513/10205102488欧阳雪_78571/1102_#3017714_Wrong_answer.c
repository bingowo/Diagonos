#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	long long b=0;
	long long xn,yn;
	long long x1,x2,y1,y2;
	long long G;
	while((b+1)*(b+1)<=n)
	{
		b++;
	}
//	printf("b:%d\n",b);
	if(b*b==n)
	{
		long long t=sqrt(n);
		if(b%2==0)
		{
			xn=-(t/2);
			yn=xn;
		}
		else
		{
			xn=t/2;
			yn=xn+1;
		}
	}
	else
	{
	if(b%2==0)
	{
		x2=(b+1)/2,y2=x2+1;
		x1=-b/2,y1=x1;
	    G=b*b+(x2-x1);//拐点大小;
	    printf("G:%d\n",G);
	    printf("(x2,y2):%d %d\n",x2,y2);
	    printf("(x1,y1):%d %d\n",x1,y1);
		if(n<=G)
		{
			xn=n-b*b+x1;
			yn=y1;
		 }
		 else{
		 	xn=x2;
		 	yn=n-(b+1)*(b+1)+y2;
		 } 
	}
	else{
		x2=b/2,y2=x2+1;
		y1=-(b+1)/2,x1=y1;
		G=b*b+(x2-x1);//拐点大小;
		if(n<=G)
		{
			xn=x2-(n-b*b);
			yn=y1;
		}
		else{
			xn=y1;
			yn=(b+1)*(b+1)-n+y1;
		}
	}
}
	
	printf("(");
	printf("%lld,",xn);
	printf("%lld",yn);
	printf(")");
	
}