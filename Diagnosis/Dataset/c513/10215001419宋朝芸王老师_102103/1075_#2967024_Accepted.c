#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int val;
    int sum;
    char how;
}POINTS;


void path(POINTS a[201][201], int m, int n){
    if(m == 0 && n == 0) return;
    if(a[m][n].how == 'R'){
        path(a,m,n-1);
        printf("R");
    }
    else{
        path(a,m-1,n);
        printf("D");
    }

}


int main()
{
    static POINTS a[201][201];

    int m,n;
    scanf("%d%d",&m,&n);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&(a[i][j].val));
            a[i][j].sum = 0;
            a[i][j].how = '\0';
        }
    }


    a[0][0].sum = a[0][0].val;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            if(i+j == 0) continue;

            if(i == 0){
                a[i][j].sum = a[i][j-1].sum + a[i][j].val;
                a[i][j].how = 'R';
            }
            else if(j == 0){
                a[i][j].sum = a[i-1][j].sum + a[i][j].val;
                a[i][j].how = 'D';
            }
            else{
                if(a[i][j-1].sum > a[i-1][j].sum){
                    a[i][j].sum = a[i-1][j].sum + a[i][j].val;
                    a[i][j].how = 'D';
                }
                else{
                    a[i][j].sum = a[i][j-1].sum + a[i][j].val;
                    a[i][j].how = 'R';
                }
            }
        }
    }


    printf("%d\n",a[m-1][n-1].sum);

    path(a,m-1,n-1);
    printf("\n");

    return 0;
}
