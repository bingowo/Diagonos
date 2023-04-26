#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int x,y,d=1;
		int count=0;
		scanf("%d %d",&x,&y);
		for(int j=0;j<20;j++){
			if((x&d)!=(y&d)){
				count++;
			}
			d=d<<1;
		}
		printf("%d\n",count);
	}
	return 0;
}