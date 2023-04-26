#include<stdio.h>
int f(int n,int p,int m,int t)
{
	if(t<=0) return 0;
	if(t==p) return f(n,p,m-1,t-1)+1;
	if(t==1) return f(n,p,m-1,t+1)+1;
	return f(n,p,m-1,t-1)+f(n,p,m-1,t+1)+2;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		int n,p,m,t;
	scanf("%d %d %d %d",&n,&p,&m,&t);
	int a=f(n,p,m,t);
	printf("%d\n",a);
	}
	return 0;
}