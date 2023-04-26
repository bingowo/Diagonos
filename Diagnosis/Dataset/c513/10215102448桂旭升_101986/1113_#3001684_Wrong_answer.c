#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int a[100][100] = {0};
int main(){
    int k, n, i, j, l;
    /*for(i = 0; i < 100; i++){
        for(j = 0; j < 100; j++){
            a[i][j] = 0;
        }
    }*/
    scanf("%d%d", &k, &n);
    a[1][99] = 1;
    if(n == 1)printf("0");
    else if(n == 2)printf("1");
    else{
        for(i = 2; i < n; i++){
            for(j = 1; j <= k; j++){
                if(i-j < 0);
                else{
                    for(l = 0; l < 100; l++){
                        a[i][l] += a[i-j][l];
                    }
                }
            }
        }
        j = 0;
        while(a[n-1][j] == 0)j++;
        //printf("%d\n", j);
        for(; j < 100; j++){
            printf("%d", a[n-1][j]);
        }
    }
    system("pause");
	return 0;
}