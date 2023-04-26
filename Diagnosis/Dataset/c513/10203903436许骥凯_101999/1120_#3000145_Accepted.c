#include<stdio.h>

int main(){
    int T; scanf("%d", &T);
    for (int i = 0; i != T; i++){
        printf("case #%d:\n", i);
        int r, c, n, k; scanf("%d%d%d%d", &r, &c, &n, &k);
        int rect[10][10] = {0};
        for (int j = 0; j != n; j++){
            int x, y; scanf("%d%d", &x, &y);
            rect[x - 1][y - 1] = 1;
        }

        int cnt = 0;
        for (int i = 0; i != r; i++)
            for (int j = 0; j != c; j++)
                for (int ii = 0; ii != r; ii++)
                    for (int jj = 0; jj != c; jj++){
                        int sum = 0;
                        for (int iii = i; iii <= ii; iii++)
                            for (int jjj = j; jjj <= jj; jjj++)
                                sum += rect[iii][jjj];
                        if (sum >= k) cnt++;
                    }
        printf("%d\n", cnt);
    }
    return 0;
}