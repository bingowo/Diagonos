#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 550
#define BigNUm 10007
#define Max 1000000

typedef long long lli;




int main(){
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        int row,col,n,k;scanf("%d%d%d%d",&row,&col,&n,&k);
        int graph[11][11]={0};
        for(int i=0;i<n;i++){
            int x,y;scanf("%d%d",&x,&y);
            graph[x][y]=1;
        }
        int cnt=0;
        for(int x1=1;x1<=row;x1++){
            for(int y1=1;y1<=col;y1++){
                for(int x2=x1;x2<=row;x2++){
                    for(int y2=y1;y2<=col;y2++){
                        int tmp=0;
                        for(int k=x1;k<=x2;k++){
                            for(int m=y1;m<=y2;m++){
                                if(graph[k][m]==1) tmp++;
                            }
                        }
                        if(tmp>=k) cnt++;
                    }
                }
            }
        }

        printf("case #%d:\n%d\n",I,cnt);


    }



    return 0;

}
