#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int r = 0, c = 0, n = 0, k = 0;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        int m[r][c]; memset(m,0,r*c*sizeof(int));
        for(int j = 0;j<n;j++){
            int x = 0, y = 0;
            scanf("%d%d",&x,&y);
            m[x-1][y-1] = 1;
        }

//        for(int j = 0;j<r;j++){
//            for(int k1 = 0;k1<c;k1++){
//                printf("%d ",m[j][k1]);
//            }
//            printf("\n");
//        }
        //行前缀1的个数
        int preOne[r][c]; memset(preOne,0,r*c*sizeof(int));
        for(int j = 0;j<r;j++){

            for(int k1 = 0;k1<c;k1++){
                if(k1==0){
                    preOne[j][k1] = m[j][k1]==1 ? 1 : 0;
                    continue;
                }
                preOne[j][k1] = preOne[j][k1-1];
                if(m[j][k1]==1){
                    preOne[j][k1]++;
                }
            }
        }
//        printf("preOne\n");
//        for(int j = 0;j<r;j++){
//            for(int k1 = 0;k1<c;k1++){
//                printf("%d ",preOne[j][k1]);
//            }
//            printf("\n");
//        }
        int res = 0;
        for(int startRow = 0;startRow<r;startRow++){//起点
            for(int startCol = 0;startCol<c;startCol++){
                for(int endRow = startRow;endRow<r;endRow++){//终点
                    for(int endCol = startCol;endCol<c;endCol++){
                        int curOneNum = 0;
                        for(int curRow=startRow;curRow<=endRow;curRow++){
                            int curRowOneNum = 0;
                            if(startCol==0){
                                curRowOneNum = preOne[curRow][endCol];
                            }
                            else{
                                curRowOneNum = preOne[curRow][endCol] - preOne[curRow][startCol-1];
                            }
                            curOneNum+=curRowOneNum;
                        }
//                        printf("%d,%d %d,%d: %d\n",startRow, startCol
//                                                , endRow, endCol, curOneNum);
                        if(curOneNum>=k){
                            res++;
                        }
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",res);
    }
    return 0;
}

//3
//4 5 10 4
//1 1
//1 3
//1 5
//2 2
//2 4
//3 1
//3 3
//3 5
//4 2
//4 4
