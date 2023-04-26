#include <stdio.h>
int T,n;
struct node
{
	int x,y;
}a[111];
int main(void)
{
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d %d",&a[i].x,&a[i].y);
		int flag = 1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i].y == a[j].x && a[i].x!=a[j].y){
					flag = 0;
					break;
				}
			}
		}
		if(!flag) printf("Poor dxw!\n");
		else printf("Lucky dxw!\n");
	}
	return 0;
}