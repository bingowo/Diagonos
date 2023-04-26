#include<stdio.h>
int n,p;
int f(int t, int m)
{
 if (m == 0)
 {
  if (t == p) return 1;
  else return 0;}
 else
 {
  if (t == n) return f(t - 1, m - 1);
  else if (t == 1) return f(t + 1, m - 1);
  else return f(t + 1, m - 1) + f(t - 1, m - 1);
 }
}

int main(){
	int T;
	scanf("%d",&T);
	for(int v=0;v<T;v++){
		int m,t;
	scanf("%d %d %d %d",&n,&p,&m,&t);
	int a=f(t,m);
	printf("%d\n",a);
	}
	return 0;
}