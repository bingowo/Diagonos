#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k,a[200][200],A[200][200];
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            scanf("%d",&a[i][j]);
    for(int i = 0;i < n;i++){
        A[i][0] = a[i][0];
        for(int j = 1;j < m;j++)
            A[i][j] = A[i][j - 1] + a[i][j];
    }
    int s = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++){
            for(int r = 1;i + r < n && j + r < m;r++){
                int sum = 0;
                for(int x = 0;x <= r;x++){
                    if(j > 0)
                        sum += A[i + x][j + r - x] - A[i + x][j - 1];
                    else
                        sum += A[i + x][j + r - x];
                }
                if(sum >= k){
                    s++;
                }
            }
            for(int r = 1;i + r < n && j - r >= 0;r++){
                int sum = 0;
                for(int x = 0;x <= r;x++){
                    if(j + x - r > 0)
                        sum += A[i + x][j] - A[i + x][j + x - r - 1];
                    else
                        sum += A[i + x][j];
                }
                if(sum >= k){
                    s++;
                }
            }
            for(int r = 1;i - r >= 0 && j + r < m;r++){
                int sum = 0;
                for(int x = 0;x <= r;x++){
                    if(j > 0)
                        sum += A[i - r + x][j + x] - A[i - r + x][j - 1];
                    else
                        sum += A[i - r + x][j + x];
                }
                if(sum >= k){
                    s++;
                }
            }
            for(int r = 1;i - r >= 0 && j - r >= 0;r++){
                int sum = 0;
                for(int x = 0;x <= r;x++){
                    if(j - x > 0)
                        sum += A[i - r + x][j] - A[i - r + x][j - x - 1];
                    else
                        sum += A[i - r + x][j];
                }
                if(sum >= k){
                    s++;
                }
            }
        }
        printf("%d",s);
    return 0;
}
