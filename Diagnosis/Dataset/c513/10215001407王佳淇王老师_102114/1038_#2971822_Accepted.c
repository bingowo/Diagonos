#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int N,M,K,ans=0;
	scanf("%d %d %d",&N,&M,&K);
	int (* a )[M+1] = (int(*)[M+1])malloc(sizeof(int) * (N+1)* (M+1));  
	//输入 
    for (int i=1;i<=N;i++)
    {
      for (int j=1;j<=M;j++)  scanf("%d",&a[i][j]);
			}
   
			//左上方 
    for (int x0 = 1; x0 <= N; x0++) {
        for (int y0 = 1; y0 <= M; y0++) {		//枚举中心点
            long long s = a[x0][y0];
            for (int r = 1; x0 - r > 0 && y0 - r > 0; r++) {	//枚举延申长度
                int lb = y0 - r;				
                int rb = y0;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s += a[x0 - r][y];
                if (s >= K) ans++;
            }}}
      //右上方 
	      for (int x0 = 1; x0 <= N; x0++) {
        for (int y0 = 1; y0 <= M; y0++) {		//枚举中心点
            long long s = a[x0][y0];
            for (int r = 1; x0 + r <=N&& y0 - r > 0; r++) {	//枚举延申长度
                int lb = y0 - r;				
                int rb = y0;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s += a[x0+r][y];
                if (s >= K) ans++;

            }}}
	    
        //左下方
		 for (int x0 = 1; x0 <= N; x0++) {
        for (int y0 = 1; y0 <= M; y0++) {		//枚举中心点
            long long s = a[x0][y0];
            for (int r = 1; x0 - r > 0 && y0+r<=M; r++) {	//枚举延申长度
                int lb = y0 ;				
                int rb = y0+r;				//计算当前行边界
                for (int y = lb; y <= rb; y++)
                    s += a[x0 - r][y];
                if (s >= K) ans++;
            }}}
	    //右下方
		for (int x0 = 1; x0 <= N; x0++) {
        for (int y0 = 1; y0 <= M; y0++) {		//枚举中心点
            long long s = a[x0][y0];
            for (int r = 1; x0 +r <=N&& y0 + r <=M; r++) {	//枚举延申长度
                int lb = y0 ;				
                int rb = y0+r ;				//计算当前行边界
                for (int y = lb; y <= rb; y++) s += a[x0+r][y];
                    if (s >= K) ans++;}}}
                //
		printf("%d ",ans);
        return 0;	
}