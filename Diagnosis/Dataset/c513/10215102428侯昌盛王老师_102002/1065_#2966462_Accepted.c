#include <stdio.h>
int V(int n)
{
	if(n==1) return 0;
	else if(n==2) return 1;
	return V(n-1)+V(n-2);
}
int K(int n)
{
	if(n<=2) return 1;
	return K(n-1)+V(n-1)-V(n-2);
}
int P(int n)
{
	if(n<=2) return 0;
	return P(n-1)+V(n)-V(n-1);
}

int main()
{
	int a,n,m,x;
	scanf("%d %d %d %d",&a,&n,&m,&x);
	int k,p,kx,px;
	k=K(n-1);
	p=P(n-1);
	int t;
	t=(m-k*a)/p;
	kx=K(x);
	px=P(x);
	int ans;
	ans=kx*a+px*t;
	printf("%d\n",ans);
	return 0;
	
	
}