#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 110
#define BigNUm 1000000007
#define Max 1000000

typedef struct{
    int num;
    char path[410];
}Ma;

Ma matrix[200][200]={0};


int main() {

    int M,N;scanf("%d%d",&M,&N);
    char R[2]="R",D[2]="D";
    for(int r=0;r<M;r++)
        for(int c=0;c<N;c++) scanf("%d",&matrix[r][c].num);

    for(int r=0;r<M;r++){
        for(int c=0;c<N;c++){
            if(r==0&&c==0);
            else if(r==0){
                matrix[r][c].num+=matrix[r][c-1].num;
                strcat(matrix[r][c].path,matrix[r][c-1].path);
                strcat(matrix[r][c].path,R);
            }
            else if(c==0){
                matrix[r][c].num+=matrix[r-1][c].num;
                strcat(matrix[r][c].path,matrix[r-1][c].path);
                strcat(matrix[r][c].path,D);
            }
            else{
                int tmp1=matrix[r][c-1].num;
                int tmp2=matrix[r-1][c].num;
                if(tmp1<tmp2){
                    matrix[r][c].num+=matrix[r][c-1].num;
                    strcat(matrix[r][c].path,matrix[r][c-1].path);
                    strcat(matrix[r][c].path,R);
                }
                else if(tmp1>tmp2){
                    matrix[r][c].num+=matrix[r-1][c].num;
                    strcat(matrix[r][c].path,matrix[r-1][c].path);
                    strcat(matrix[r][c].path,D);
                }
            }
        }
    }

    printf("%d\n%s",matrix[M-1][N-1].num,matrix[M-1][N-1].path);
    return 0;
}
