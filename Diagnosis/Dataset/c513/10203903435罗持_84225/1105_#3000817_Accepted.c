#include <stdio.h>
int a[111][111] = {0};
int res[111][111] = {0};
int w,h;
int cal(int x,int y){
	int b[10] = {0};
	b[0] = (a[x-1][y-1]>=a[x][y])?1:0;
	b[1] = (a[x-1][y]>=a[x][y])?1:0;
	b[2] = (a[x-1][y+1]>=a[x][y])?1:0;
	b[3] = (a[x][y+1]>=a[x][y])?1:0;
	b[4] = (a[x+1][y+1]>=a[x][y])?1:0;
	b[5] = (a[x+1][y]>=a[x][y])?1:0;
	b[6] = (a[x+1][y-1]>=a[x][y])?1:0;
	b[7] = (a[x][y-1]>=a[x][y])?1:0;
	int mmin = (1<<9);
	for(int st=0;st<8;st++){
		int now = 0;
		for(int j=0;j<8;j++){
			now = now*2+b[(j+st)%8];
		}
		if(now < mmin) mmin = now;
	}
	return mmin;
}
int main(void)
{
	scanf("%d %d",&w,&h);
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			scanf("%d",&a[i][j]);
	for(int i=2;i<h;i++){
		for(int j=2;j<w;j++){
			res[i][j] = cal(i,j);
			if(j==w-1) printf("%d",res[i][j]);
			else printf("%d ",res[i][j]);
		}
		putchar('\n');
	}
	return 0;
}