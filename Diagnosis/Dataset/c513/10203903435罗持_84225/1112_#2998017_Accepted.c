#include <stdio.h>
int T,n;
int main(void)
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int cnt = 0;
		for(int i=0;i*4<=n;i++){
			int num1 = n-i*4;
			for(int j=0;j*3<=num1;j++){
				int num2 = num1-j*3;
				cnt += num2 / 2+1;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}