#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        int r,c,n,k;//行，列，1的个数，矩形的k
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int m[r+1][c+1],p[n][2];
        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++){
                m[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%d %d",&p[i][0],&p[i][1]);
            m[p[i][0]][p[i][1]]=1;
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                printf("%d",m[i][j]);
            }
            printf("\n");
        }
        
    }
    return 0;
}
