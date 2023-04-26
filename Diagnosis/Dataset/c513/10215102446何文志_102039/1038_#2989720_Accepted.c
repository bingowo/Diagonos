#include <stdio.h>
#include <stdlib.h>


int min(int a, int b){
    return a>b ? a : b;
}
//前缀和
int main()
{
    int n = 0, m = 0, k = 0;
    scanf("%d%d%d",&n,&m,&k);
    int nums[n][m];memset(nums,0,n*m*sizeof(int));
    int preSum[n][m];memset(preSum,0,n*m*sizeof(int));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&nums[i][j]);
        }
        for(int j = 0;j<m;j++){
            for(int k = 0;k<=j;k++){
                preSum[i][j] += nums[i][k];
            }
        }
    }

//    printf("nums\n");
//    for(int i = 0;i<n;i++){
//        for(int j = 0;j<m;j++){
//            printf("%d ",nums[i][j]);
//        }
//        printf("\n");
//    }
//    printf("preSum\n");
//        for(int i = 0;i<n;i++){
//        for(int j = 0;j<m;j++){
//            printf("%d ",preSum[i][j]);
//        }
//        printf("\n");
//    }

    int res = 0;

    // .
    // ..
    // ...
    for(int startRow = 0;startRow<n-1;startRow++){
        for(int startCol = 0;startCol<m-1;startCol++){
            int curTotalSum = nums[startRow][startCol];//以当前起点向下作等腰三角形的和
            //printf("start: %d, %d, %d\n",startRow, startCol, curTotalSum);
            for(int len = 2;len<=min(n,m);len++){//边长
                int endRow = startRow+len-1;
                int endCol = startCol+len-1;
                if(endRow<n&&endCol<m){
                    int curRowSum = preSum[endRow][endCol] - preSum[endRow][startCol]
                                                            + nums[endRow][startCol];
                    curTotalSum += curRowSum;
                    //printf("end = %d, %d\, %d\n",endRow,endCol,nums[endRow][endCol]);
                    //printf("len = %d, curRowSum = %d, curTotalSum = %d\n",len,curRowSum,curTotalSum);
                    if(curTotalSum>=k){
                        res++;
                    }
                }
            }
        }
    }


//5 4 10
//6 2 1 7
//4 2 2 3
//2 3 7 9
//1 2 5 5
//3 6 4 7
    // ...
    // ..
    // .
    for(int startRow = n-1;startRow>0;startRow--){
        for(int startCol = 0;startCol<m-1;startCol++){
            int curTotalSum = nums[startRow][startCol];//以当前起点向上作等腰三角形的和
            //printf("start: %d, %d, %d\n",startRow, startCol, curTotalSum);
            for(int len = 2;len<=min(n,m);len++){//边长
                int endRow = startRow-len+1;
                int endCol = startCol+len-1;
                if(endRow>=0&&endCol<m){
                    int curRowSum = preSum[endRow][endCol] - preSum[endRow][startCol]
                                                            + nums[endRow][startCol];
                    curTotalSum += curRowSum;
                    //printf("end = %d, %d\, %d\n",endRow,endCol,nums[endRow][endCol]);
                    //printf("len = %d, curRowSum = %d, curTotalSum = %d\n",len,curRowSum,curTotalSum);
                    if(curTotalSum>=k){
                        res++;
                    }
                }
            }
        }
    }

    // ...
    //  ..
    //   .
    for(int startRow = n-1;startRow>0;startRow--){
        for(int startCol = m-1;startCol>0;startCol--){
            int curTotalSum = nums[startRow][startCol];//以当前起点向下作等腰三角形的和
            //printf("start: %d, %d, %d\n",startRow, startCol, curTotalSum);
            for(int len = 2;len<=min(n,m);len++){//边长
                int endRow = startRow-len+1;
                int endCol = startCol-len+1;
                if(endRow>=0&&endCol>=0){
                    int curRowSum = preSum[endRow][startCol] - preSum[endRow][endCol]
                                                            + nums[endRow][endCol];
                    curTotalSum += curRowSum;
                    //printf("end = %d, %d\, %d\n",endRow,endCol,nums[endRow][endCol]);
                    //printf("len = %d, curRowSum = %d, curTotalSum = %d\n",len,curRowSum,curTotalSum);
                    if(curTotalSum>=k){
                        res++;
                    }
                }
            }
        }
    }

    //   .
    //  ..
    // ...
    for(int startRow = 0;startRow<n-1;startRow++){
        for(int startCol = m-1;startCol>0;startCol--){
            int curTotalSum = nums[startRow][startCol];//以当前起点向下作等腰三角形的和
            //printf("start: %d, %d, %d\n",startRow, startCol, curTotalSum);
            for(int len = 2;len<=min(n,m);len++){//边长
                int endRow = startRow+len-1;
                int endCol = startCol-len+1;
                if(endRow<n&&endCol>=0){
                    int curRowSum = preSum[endRow][startCol] - preSum[endRow][endCol]
                                                            + nums[endRow][endCol];
                    curTotalSum += curRowSum;
                    //printf("end = %d, %d\, %d\n",endRow,endCol,nums[endRow][endCol]);
                    //printf("len = %d, curRowSum = %d, curTotalSum = %d\n",len,curRowSum,curTotalSum);
                    if(curTotalSum>=k){
                        res++;
                    }
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
