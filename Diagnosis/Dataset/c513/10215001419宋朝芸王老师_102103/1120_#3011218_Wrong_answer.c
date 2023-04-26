#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 11

int myenum(int F[Max][Max], int row, int col, int n, int k){
    int i,j;
    int res = 0;

    /***special cases for 1*1 matrix***/
    if(k == 1) res += n;

    /***left up***/
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            //start enum: right down point set:m[i][j];
            for(int a = 0; a <= i; a++){ //height:a+1
                for(int b = 0; b <= j; b++){ //width:b+1
                    //special cases
                    if(a == 0 && b == 0) continue;
                    //cal num of one
                    int temp = 0;
                    for(int q = 0; q <= a; q++){
                        if(j <= b) temp += F[i-q][j];
                        else temp += F[i-q][j]-F[i-q][j-b-1];
                    }
                    //judge
                    if(temp >= k) res++;
                }
            }
        }
    }


    /***right up***/
    /*for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            //start enum: left down point set:m[i][j];
            for(int a = 0; a <= i; a++){ //height:a+1
                for(int b = 0; b <= (col-j); b++){ //width:b+1
                    //special
                    if(a == 0 && b == 0) continue;
                    //cal num of one
                    int temp = 0;
                    for(int q = 0; q <= a; q++)
                        if(j == 0) temp += F[i-q][j+b];
                        else temp += F[i-q][j+b]-F[i-q][j-1];
                    //judge
                    if(temp == k) res++;
                }
            }
        }
    }*/

    /***left down***/
    /*for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            //start enum: right up point set:m[i][j];
            for(int a = 0; a <= (row-i); a++){ //height:a+1
                for(int b = 0; b <= j; b++){ //width:b+1
                    //special
                    if(a == 0 && b == 0) continue;
                    //cal num of one
                    int temp = 0;
                    for(int q = 0; q <= a; q++)
                        if(j <= b) temp += F[i+q][j];
                        else temp += F[i+q][j]-F[i+q][j-b-1];
                    //judge
                    if(temp == k) res++;
                }
            }
        }
    }*/

    /***right down***/
    /*for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){

            //start enum: left up point set:m[i][j];
            for(int a = 0; a <= (row-i); a++){ //height:a+1
                for(int b = 0; b <= (col-j); b++){ //width:b+1

                    if(a == 0 && b == 0) continue;
                    //cal num of one
                    int temp = 0;
                    for(int q = 0; q <= a; q++)
                        if(j == 0) temp += F[i+q][j+b];
                        else temp += F[i+q][j+b]-F[i+q][j-1];

                    //judge
                    if(temp >= k) res++;
                }
            }
        }
    }*/

    return res;
}

int main()
{
    int T,R;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int matrix[Max][Max], F[Max][Max];
        memset(matrix,0,Max*Max);
        memset(F,0,Max*Max);

        int row, col, n, k, ans = 0;
        scanf("%d%d%d%d",&row,&col,&n,&k);

        for(int i = 0; i < n; i++){
            int r,c;
            scanf("%d%d",&r,&c);
            matrix[r-1][c-1] = 1;
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(j == 0) F[i][j] = matrix[i][j];
                else F[i][j] = F[i][j-1] + matrix[i][j];
            }
        }

        ans = myenum(F,row,col,n,k);
        printf("case #%d:\n%d\n",R,ans);
    }


    return 0;
}
