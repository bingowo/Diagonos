#include <stdio.h>
int T;
int main(void)
{
	scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		int num;
		scanf("%d",&num);
		int cnt5 = 0;
		for(int i=1;i<=num;i++){
			int x = i;
			while(x%5==0){
				cnt5++;
				x /=5;
			}
		} 
		printf("case %d:\n",kase);
		printf("%d\n",cnt5);
	}
	return 0;
}