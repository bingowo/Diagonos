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
    d %= 360; ma = m > n ? m : n;
    if(c == 'L')d = 360 - d;
    int **a = (int**)malloc(sizeof(int*)*ma);
    for(j = 0; j < ma; j++)a[j] = (int*)malloc(sizeof(int)*ma);
    for(j = 0; j < m; j++){
        for(k = 0; k < n; k++){
            scanf("%d", &ans);
            a[j][k] = ans;
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
    for(j = 0; j < ma; j++){
        for(k = 0; k < ma; k++){
            if(a[j][k] != -1){
                printf("%d", a[j][k]);
                if(k != ma-1)printf(" ");
            }
        }
        printf("\n");
    }
    free(a);
    //system("pause");
	return 0;
}