#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	int x,y;
	int sum;
	for (i=0;i<T;i++){
		sum=0;
		scanf("%d %d",&x,&y);
		while((x!=0)||(y!=0)){
			if ((x&1)!=(y&1)){
				sum+=1;
			}
			x=x>>1;
			y=y>>1;
		}
		printf("%d\n",sum);
	}
	return 0;
}