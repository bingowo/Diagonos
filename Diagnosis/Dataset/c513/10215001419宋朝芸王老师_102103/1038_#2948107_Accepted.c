#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    int a[200][200] = {0};
    //int **a =(int**)malloc(n*m*sizeof(int));
    //int **F =(int**)malloc(n*m*sizeof(int));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //input
            scanf("%d",&a[i][j]);
            //cal add
            //if(j == 0) F[i][j] = a[i][j];
            //else F[i][j] = F[i][j-1] + a[i][j];
        }
    }

    long long int ans = 0;

    //left up
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //start
            int temp = a[i][j];
            //enum
            for(int r = 1; i - r >= 0 && j - r >= 0; r++){
                if(temp >= k){
                    ans ++;
                    continue;
                }
                for(int t = 0; t <= r; t++){
                    temp += a[i-t][j-r+t];
                }
                if(temp >= k){
                    ans ++;
                }
            }
        }
    }

    //right up
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //start
            int temp = a[i][j];
            //enum
            for(int r = 1; i - r >= 0 && j + r < m; r++){
                if(temp >= k){
                    ans ++;
                    continue;
                }
                for(int t = 0; t <= r; t++){
                    temp += a[i-t][j+r-t];
                }
                if(temp >= k){
                    ans ++;
                }
            }
        }
    }

    //left down
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //start
            int temp = a[i][j];
            //enum
            for(int r = 1; i + r < n && j - r >= 0; r++){
                if(temp >= k){
                    ans ++;
                    continue;
                }
                for(int t = 0; t <= r; t++){
                    temp += a[i+t][j-r+t];
                }
                if(temp >= k){
                    ans ++;
                }
            }
        }
    }

    //right down
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //start
            int temp = a[i][j];
            //enum
            for(int r = 1; i + r < n && j + r < m; r++){
                if(temp >= k){
                    ans ++;
                    continue;
                }
                for(int t = 0; t <= r; t++){
                    temp += a[i+t][j+r-t];
                }
                if(temp >= k){
                    ans ++;
                }
            }
        }
    }

    printf("%lld",ans);

    return 0;
}
