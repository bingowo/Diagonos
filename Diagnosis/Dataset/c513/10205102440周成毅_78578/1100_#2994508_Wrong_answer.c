#include <stdio.h>
#include <string.h>

void trans(char a[], int b[], int c[]) {
    unsigned len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (a[i] == 'U')
            b[i] = 1;
        else if (a[i] == 'D')
            b[i] = -1;
        else if (a[i] == 'L')
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
    unsigned len = strlen(command);
    int line = 0, col = 0;
    for (int i = 0; i < len; i++) {
        line += lr[i];
        col += ud[i];
    }
    long long x, y;
    for (int i = 0; i < q; i++) {
        int ci;
        scanf("%lld %lld", &x, &y);
        int flag=1;
        if(x==0 && y==0){
            printf("Yes\n");
            flag=0;
        }
        if(flag){
            long long xc=0,yc=0;
            for(int j=0;j<len;j++){
                xc+=lr[j];
                yc+=ud[j];
                if(xc==x && yc==y){
                    printf("Yes\n");
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            if(line && col){
                if(x/line>=0 && y/col>=0 && x/line==y/col && x%line==0 && y%col==0){
                    printf("Yes\n");
                    flag=0;
                    break;
                } else{
                    int xx=x/line;
                    int yy=y/col;
                    if(xx>0 && yy>0)
                        ci=xx>yy?yy:xx;
                    else if(xx>0 && yy<0)
                        ci=xx-1;
                    else if(xx<0 && yy>0)
                        ci=yy-1;
                    else
                        ci=-1;
                }
            } else{
                if(!line && col)
                    ci=y/col-1;
                else if(line && !col)
                    ci=x/line-1;
                else
                    ci=-1;
            }
        }
        if(flag){
            if(ci>=0){
                long xc = ci * line;
                long long yc = ci * col;
                for (int j = 0; j < 4; j++) {
                    if (flag) {
                        for (int k = 0; k < len; k++) {
                            xc += lr[k];
                            yc += ud[k];
                            if (xc == x && yc == y) {
                                printf("Yes\n");
                                flag = 0;
                                break;
                                
                            }
                        }
                    }
                }
            }
        }
        if(flag)
            printf("No\n");
    }
    return 0;
}
