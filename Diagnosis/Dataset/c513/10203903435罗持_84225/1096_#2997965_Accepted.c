#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int T,n;
int a[111][111] = {0};
int main(void)
{
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			if(a[x][y]==0){
				a[x][0]++;
				a[x][y] = 1;
			}
		}
		int flag = 1;
		for(int i=1;i<=100;i++){
			if(a[i][0]>=2){
				flag = 0;
				break;
			}
		}
		if(!flag){
			printf("Poor dxw!\n");
			continue;
		}
		for(int i=1;i<=100;i++){
			if(a[i][0]==1){
				int find = 0;
				for(int j=1;j<=100;j++){
					if(a[j][i]){
						flag = 0;
						break;
					}
				}
			}
		}
		if(!flag) printf("Poor dxw!\n");
		else printf("Lucky dxw!\n"); 
	}
	return 0;
}