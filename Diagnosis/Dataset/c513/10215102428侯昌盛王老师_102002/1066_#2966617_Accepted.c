#include <stdio.h>
int sum=0;
int h(int n,int p,int m,int t)
{
	if(m==0&&p==t)  return 1;
	else if(m==0&&p!=t) return 0;
	else if(p==1) return sum+h(n,p+1,m-1,t);
	else if(p==n) return sum+h(n,p-1,m-1,t);
	else return sum+h(n,p+1,m-1,t)+h(n,p-1,m-1,t);
	
}
int main()
{
	int cas,n,p,m,t,i;
	scanf("%d",&cas);
	for(i=0;i<cas;i++)
	{
		scanf("%d %d %d %d",&n,&p,&m,&t);
		int k;
		k=h(n,p,m,t);
		printf("%d\n",k);
		
	}
	return 0;

}