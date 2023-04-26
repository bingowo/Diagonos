#include<stdio.h>
int count (unsigned int n) {
 int co = 0;
 unsigned int one = 1;
 for (int i = 0; i < 64; i++) {
  if (n & one)
   co++;
  n = n >> 1;
 }
 return co;
}
int main()
{
	int T,t;
	unsigned int x,y,ans;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		scanf("%u %u",&x,&y);
		ans=x^y;
		t=count(ans);
		printf("%d\n",t);
	}
	return 0;
 } 