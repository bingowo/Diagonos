#include<stdio.h>

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int pro; scanf("%d", &pro);
        int cnt = 0;
        for (int j = 0; j <= pro / 4; j++)
            for (int k = 0; k <= pro / 3; k++)
                for (int m = 0; m <= pro / 2; m++)
                    if (4 * j + 3 * k + 2 * m <= pro)
                     cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}