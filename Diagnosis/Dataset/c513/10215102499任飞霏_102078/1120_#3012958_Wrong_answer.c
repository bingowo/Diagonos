#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int r,c,n,k;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        int table[r][c];
        memset(table,0,sizeof(table));
        for(int i=0;i<n;i++){
            int m,n;
            scanf("%d%d",&m,&n);
            table[m-1][n-1]=1;
        }
        int sum=0;
        for(int x1=0; x1<c; x1++) {
			for(int y1=0; y1<r; y1++) {
				for(int x2=x1; x2<c; x2++) {
					for(int y2=y1; y2<r; y2++) {
						int ans=0;
						for(int x=x1; x<=x2; x++) {
							for(int y=y1; y<=y2; y++) {
								if(table[x][y]==1)
									ans++;
							}
						}
						if(ans>=k)
							sum++;
					}
				}
			}
		}
        printf("case #%d:\n%d\n",t,sum);
    }
    return 0;
}
