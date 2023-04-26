#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int cnt = 0;
    while(T-->0){
        int p[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
        int x[3][3];
        for(int a = 0;a<3;a++){
            for(int b = 0;b<3;b++){
                scanf("%d",&x[a][b]);
            }
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(i == 0){
                    if(j == 0){
                        p[i+1][j]+=x[i][j];
                        p[i][j+1]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                    else if(j == 1){
                        p[i][j-1]+=x[i][j];
                        p[i+1][j]+=x[i][j];
                        p[i][j+1]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                    else if(j == 2){
                        p[i][j-1]+=x[i][j];
                        p[i+1][j]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                }
                else if(i == 1){
                    if(j == 0){
                        p[i-1][j]+=x[i][j];
                        p[i+1][j]+=x[i][j];
                        p[i][j+1]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                    else if(j == 1){
                        p[i-1][j]+=x[i][j];
                        p[i+1][j]+=x[i][j];
                        p[i][j-1]+=x[i][j];
                        p[i][j+1]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                    else if(j == 2){
                        p[i-1][j]+=x[i][j];
                        p[i][j-1]+=x[i][j];
                        p[i+1][j]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                }
                else if(i == 2){
                    if(j == 0){
                        p[i-1][j]+=x[i][j];
                        p[i][j+1]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                    else if(j == 1){
                        p[i][j-1]+=x[i][j];
                        p[i-1][j]+=x[i][j];
                        p[i][j+1]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                    else if(j == 2){
                        p[i][j-1]+=x[i][j];
                        p[i-1][j]+=x[i][j];
                        p[i][j]+=x[i][j];
                    }
                }
        }
    }
    printf("case #%d:\n",cnt);
    for(int m = 0;m<3;m++){
        for(int n = 0;n<3;n++){
            if(p[m][n]%2 == 0) printf("0 ");
            else printf("1 ");
        }
        printf("\n");
    }
    cnt++;
    }

}
