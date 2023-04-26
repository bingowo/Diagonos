#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <limits.h>
int main(){
	int m, n, i, j, sub = 0;
    int d[16] = {0};
    int min = INT_MAX;
    scanf("%d%d", &n, &m);
    int a[m][n];
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(i = 1; i < m-1; i++){
        for(j = 1; j < n-1; j++){
            d[0] = a[i-1][j-1]>=a[i][j];
            d[8] = d[0];
            d[1] = a[i-1][j]>=a[i][j];
            d[9] = d[1];
            d[2] = a[i-1][j+1]>=a[i][j];
            d[10] = d[2];
            d[3] = a[i][j+1]>=a[i][j];
            d[11] = d[3];
            d[4] = a[i+1][j+1]>=a[i][j];
            d[12] = d[4];
            d[5] = a[i+1][j]>=a[i][j];
            d[13] = d[5];
            d[6] = a[i+1][j-1]>=a[i][j];
            d[14] = d[6];
            d[7] = a[i][j-1]>=a[i][j];
            d[15] = d[7];
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    sub = sub*2 + d[k+l];
                }
                if(sub < min)min = sub;
                sub = 0;
            }
            //printf("%d", min);
            printf("%d", min); sub = 0;min = INT_MAX;
            if(j != n-2)printf(" ");
            else printf("\n");
        }
    }
    system("pause");
	return 0;
}