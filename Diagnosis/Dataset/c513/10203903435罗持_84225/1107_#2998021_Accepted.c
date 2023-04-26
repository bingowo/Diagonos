#include <stdio.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		int a[5][5];
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				a[i][j] = 1;
		int b[5][5] = {0};
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				int x;
				scanf("%d",&x);
				x &= 1;
				if(x==1){
					a[i][j] ^= 1;
					a[i-1][j] ^= 1;
					a[i+1][j] ^= 1;
					a[i][j-1] ^= 1;
					a[i][j+1] ^= 1;
				}
			}
		}
		printf("case #%d:\n",kase);
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++)
				printf("%d ",a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}