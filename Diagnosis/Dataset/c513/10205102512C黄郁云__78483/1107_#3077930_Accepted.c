#include <stdio.h>
#include <stdlib.h>

int table[5][5];
int change[5][5];
int ans[5][5];


int main(){
    int qust = 0;
    scanf("%d",&qust);
    for(int i = 0; i <qust;i++){
        printf("case #%d:\n",i);
        for(int m = 0;m<=4;m++){
            for(int n = 0;n<=4;n++){
                change[m][n] = 0;
                ans[m][n] = 0;
            }
        }
        for(int m = 1;m <=3;m++){
            for(int n = 1;n<=3;n++){
                scanf("%d",&change[m][n]);
            }
        }

        for(int m = 1;m<=3;m++){
            for(int n = 1;n <=3;n++){
                ans[m][n] = change[m][n]+change[m-1][n]+change[m+1][n]+change[m][n-1]+change[m][n+1];
            }
        }

        for(int m = 1;m <= 3;m++){
            for(int n = 1;n <= 3;n++){
                if(ans[m][n]&1){//
                    printf("0 ");
                }else{
                    printf("1 ");
                }
            }
            printf("\n");
        }


    }
}