#include<stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	for(int i = 0; i < t; i++) {
		int r,c,n,k;
		scanf("%d%d%d%d",&r,&c,&n,&k);
		int flag[r][c]={0,0};
		for(int j = 0; j < n; j++) {
			int x,y;
			scanf("%d%d",&x,&y);
			flag[x-1][y-1]=1;
		}
		int sum=0;
		for(int x1=0; x1<r; x1++) {
			for(int y1=0; y1<c; y1++) {
				for(int x2=x1; x2<r; x2++) {
					for(int y2=y1; y2<c; y2++) {
						int ans=0;
						for(int x=x1; x<=x2; x++) {
							for(int y=y1; y<=y2; y++) {
								if(flag[x][y]==1)
									ans++;
							}
						}
						if(ans>=k)
							sum++;
					}
				}
			}
		}
		printf("case #%d:\n%d\n",i,sum);
	}
	return 0;
}