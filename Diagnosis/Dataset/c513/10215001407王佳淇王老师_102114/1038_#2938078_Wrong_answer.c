#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int n,m,k,ans=0;
	scanf("%d %d %d",&n,&m,&k);
	int (*a)[m] = (int(*)[m])malloc(sizeof(int) * (n)* (m)); 
	//输入 
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=m;j++)  scanf("%d",&a[i][j]);
			}
			//左上方 
    for (int x0=1;x0<=n;x0++) {
        for (int y0=1;y0<=m;y0++) {		//枚举中心点
            long long s=a[x0][y0];
            for (int r =1; x0 - r > 0 && y0 - r > 0; r++) {	//枚举延申长度
                int lb = y0-r;				
                int rb = y0;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s+= a[x0 - r][y];
                if (s>= k) ans++;
            }}}
      //左下方
	    for (int x0=1;x0<=n;x0++) {
        for (int y0=1;y0<=m;y0++) {		//枚举中心点
            long long s=a[x0][y0];
            for (int r =1; x0-r> 0 && y0+r<m; r++) {	//枚举延申长度
                int lb = y0;				
                int rb = y0+r;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s+= a[x0 - r][y];
                if (s>= k) ans++;
            }}}    
        //右上方
		 for (int x0=1;x0<=n;x0++) {
        for (int y0=1;y0<=m;y0++) {		//枚举中心点
            long long s=a[x0][y0];
            for (int r =1; x0+r<n && y0-r> 0; r++) {	//枚举延申长度
                int lb = y0-r;				
                int rb = y0;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s+= a[x0 - r][y];
                if (s>= k) ans++;
            }}}
	    //右下方
		 for (int x0=1;x0<=n;x0++) {
        for (int y0=1;y0<=m;y0++) {		//枚举中心点
            long long s=a[x0][y0];
            for (int r =1; x0+r<n && y0+r<m; r++) {	//枚举延申长度
                int lb = y0;				
                int rb = y0+r;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s+= a[x0 - r][y];
                if (s>= k) ans++;
            }}}
		printf("%d ",ans);
return 0;	
}