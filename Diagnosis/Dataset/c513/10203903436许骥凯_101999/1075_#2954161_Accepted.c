#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int res[201][201] = {{0}};
    int arr[201][201] = {{0}};
    int m, n; scanf("%d%d", &m, &n);
    char ***way = (char***)malloc(sizeof(char**) * m);
    for (int i = 0; i != m; i++) way[i] = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i != m; i++)
        for (int j = 0; j != n; j++){
            scanf("%d", &arr[i][j]);
            way[i][j] = (char*)malloc(sizeof(char) * 500);
            memset(way[i][j], 0, 500);
        }
    res[0][0] = arr[0][0];
    for (int i = 0; i != m; i++){
        for (int j = 0; j != n; j++){
            if (i == 0 && j == 0) continue;
            if (i == 0){
                int wlen = strlen(way[i][j-1]);
                res[i][j] = res[i][j-1] + arr[i][j];
                strcpy(way[i][j], way[i][j-1]);
                way[i][j][wlen++] = 'R';
            } 
            else if (j == 0){
                int wlen = strlen(way[i-1][j]);
                res[i][j] = res[i-1][j] + arr[i][j];
                strcpy(way[i][j], way[i-1][j]);
                way[i][j][wlen++] = 'D';
            }
            else{
                int temp1 = res[i-1][j];
                int temp2 = res[i][j-1];
                if (temp1 > temp2){
                    int wlen = strlen(way[i][j-1]);
                    res[i][j] = temp2 + arr[i][j];
                    strcpy(way[i][j], way[i][j-1]);
                    way[i][j][wlen++] = 'R';
                }
                else{
                    int wlen = strlen(way[i-1][j]);
                    res[i][j] = temp1 + arr[i][j];
                    strcpy(way[i][j], way[i-1][j]);
                    way[i][j][wlen++] = 'D';
                }
            }
        }
    }

    printf("%d\n%s\n", res[m-1][n-1], way[m-1][n-1]);
    for (int i = 0; i != m; i++)
        for (int j = 0; j != n; j++)
            free(way[i][j]);
    for (int i = 0; i != m; i++)
        free(way[i]);
    free(way);
    return 0;
}