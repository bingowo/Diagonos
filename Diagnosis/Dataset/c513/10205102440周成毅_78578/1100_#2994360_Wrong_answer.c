#include <stdio.h>
#include <string.h>

void trans(char a[], int b[], int c[]) {
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (a[i] == 'U')
            b[i] = 1;
        else if (a[i] == 'D')
            b[i] = -1;
        else if (a[i] = 'L')
            c[i] = -1;
        else
            c[i] = 1;
    }
}

int main() {
    char command[101];
    int ud[101], lr[101];
    memset(ud, 0, sizeof(ud));
    memset(lr, 0, sizeof(lr));
    int q;
    scanf("%s", command);
    scanf("%d", &q);
    trans(command, ud, lr);
    int len = strlen(command);
    int line = 0, col = 0;
    for (int i = 0; i < len; i++) {
        line += lr[i];
        col += ud[i];
    }
    long long x, y;
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &x, &y);
        if (line != 0 && col != 0) {
            if (x==0 && y==0 || x / line == y / col && x % line == 0 && y % col == 0)
                printf("Yes\n");
            else if (x / line == y / col) {
                long long u = x - (x / line) * line;
                long long v = y - (y / col) * col;
                int flag = 1;
                for (int j = 0; j < len; j++) {
                    u -= lr[j];
                    v -= ud[j];
                    if (u == 0 && v == 0) {
                        printf("Yes\n");
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                    printf("No\n");
            } else {
                printf("No\n");
            }
        } else if (line != 0 && col == 0) {
            int xc=0,yc=0,flag1=1;
            for(int j=0;j<len;j++){
                xc+=lr[j];
                yc+=ud[j];
                if(xc==x && yc==y){
                    printf("Yes\n");
                    flag1=0;
                    break;
                }
            }
            if(flag1){
                if (x==0 && y==0 ||x % line == 0 && x/line>0 && y==0)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        } else if (line == 0 && col != 0) {
            int xc=0,yc=0,flag1=1;
            for(int j=0;j<len;j++){
                xc+=lr[j];
                yc+=ud[j];
                if(xc==x && yc==y){
                    printf("Yes\n");
                    flag1=0;
                    break;
                }
            }
            if(flag1){
                if (x==0 && y==0 ||y % col == 0 && y/col>0 && x==0)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
    }
    return 0;
}
