#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int left(int **a, int m, int n, int d){
    int i, j, k, l, ans = 0, sub = 0, o, p;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            
            for(k = 0; k <=i; k++){
                for(l = 0; l <= j; l++){sub = 0;
                    for(o = k; o <=i; o++){
                        for(p = l; p <= j; p++){
                            sub += a[o][p];
                        }
                    }if(sub >= d)ans++;
                }
            }
            
        }
    }
    return ans;
}
/*int right(int **a, int m, int n, int d){
    int i, j, k, l, ans = 0, sub = 0, o, p;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(i > 0 &&i < m-1 && j > 0 && j < n-1){
                for(k = 1; k < m; k++){
                    for(l = 1; l < n; l++){
                        
                        if(sub >= d)ans++;
                        sub = 0;
                    }
                }
            }
        }
    }
    return ans;
}*/
int main(){
	int i, j, t, m, n, c, k, index1, index2, ans, d;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        printf("case #%d:\n", i);
        scanf("%d%d%d%d", &m, &n, &c, &d);
        int **a = (int**)malloc(sizeof(int*)*m);
        for(j = 0; j < m; j++)a[j] = (int*)malloc(sizeof(int)*n);
        for(j = 0; j < m; j++){
            for(k = 0; k < n; k++){
                a[j][k] = 0;
            }
        }
        for(j = 0; j < c; j++){
            scanf("%d%d", &index1, &index2);
            a[index1-1][index2-1] = 1;
        }
        ans = left(a, m, n, d);//right(a, m, n, d);
        printf("%d\n", ans);
        /*for(j = 0; j < m; j++){
            for(k = 0; k < n; k++){
                printf("%d ", a[j][k]);
            }
        }*/
        ans = 0;
        free(a);
    }
    system("pause");
	return 0;
}