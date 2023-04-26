#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void r(int **a, int d, int m){
    int temp, i, j, k;
    for(k = 0; k < d; k++){
        for(i = 0; i < m/2; i++){
            for(j = 0; j < m; j++){
                temp = a[i][j];
                a[i][j] = a[m-i-1][j];
                a[m-i-1][j] = temp;
            }
        }
        for(i = 0; i < m; i++){
            for(j = i+1; j < m; j++){
                temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }
    }
    
}
int main(){
	int i, j, m, n, d, k, ma, ans, flag;
    char c;
    scanf("%d%d%d%s", &n, &m, &d, &c);
    printf("%d %d %d", n, m, d);
    d %= 360; ma = m > n ? m : n;
    if(c == 'L')d = 360 - d;
    int **a = (int**)malloc(sizeof(int*)*ma);
    for(j = 0; j < ma; j++)a[j] = (int*)malloc(sizeof(int)*ma);
    for(j = 0; j < m; j++){
        for(k = 0; k < n; k++){
            scanf("%d", &a[j][k]);
        }
    }
    if(ma == n && ma == m);
    else if(ma == n && ma != m){
        for(j = m; j < ma; j++){
            for(k = 0; k < ma; k++){
                a[j][k] = -1;
            }
        }
    }
    else{
        for(j = 0; j < ma; j++){
            for(k = n; k < ma; k++){
                a[j][k] = -1;
            }
        }
    }
    r(a, d/90, ma);
    if(d/90%2){
        int temp = n;
        n = m; m = temp;
    }
    printf("%d %d\n", n, m);
    if(a[0][0] == -1 && a[0][1] == -1){
        for(j = 1; j < ma; j++){
            for(k = 0; k < ma; k++){
                printf("%d", a[j][k]);
                if(k != ma-1)printf(" ");
            }
            printf("\n");
        }
    }
    else if(a[0][0] == -1 && a[1][0] == -1){
        for(j = 0; j < ma; j++){
            for(k = 1; k < ma; k++){
                printf("%d", a[j][k]);
                if(k != ma-1)printf(" ");
            }
            printf("\n");
        }
    }
    else if(a[ma-1][0] == -1 && a[ma-1][1] == -1){
        for(j = 0; j < ma-1; j++){
            for(k = 0; k < ma; k++){
                printf("%d", a[j][k]);
                if(k != ma-1)printf(" ");
            }
            printf("\n");
        }
    }
    else if(a[ma-1][ma-1] == -1 && a[ma-2][ma-1] == -1){
        for(j = 0; j < ma; j++){
            for(k = 0; k < ma-1; k++){
                printf("%d", a[j][k]);
                if(k != ma-1)printf(" ");
            }
            printf("\n");
        }
    }
    free(a);
    system("pause");
	return 0;
}