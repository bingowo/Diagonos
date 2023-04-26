#include<stdio.h>

char dir[1000] = {0}; int times = 0;

void direct(int x, int y){
    if (x % 2){
        int e = x - 1, w = x + 1;
        y /= 2, e /= 2, w /= 2;
        if (!y && !e){
            dir[times++] = 'E';
            return;
        }

        if (!y && !w){
            dir[times++] = 'W';
            return;
        }
        
        if ((y + e) % 2){
            dir[times++] = 'E';
            direct(e, y);
        }

        else if ((y + w) % 2){
            dir[times++] = 'W';
            direct(w, y);
        }
    }

    else if (y % 2){
        int n = y - 1, s = y + 1;
        x /= 2, n /= 2, s /= 2;
        if (!x && !n){
            dir[times++] = 'N';
            return;
        } 
        
        if (!x && !s){
            dir[times++] = 'S';
            return;
        }

        if ((x + n) % 2){
            dir[times++] = 'N';
            direct(x, n);
        }

        else if ((x + s) % 2){
            dir[times++] = 'S';
            direct(x, s);
        }
    }
}


int main(){
    int x, y; scanf("%d%d", &x, &y);
    if (x == 0 && y == 0){
        printf("0\n");
        return 0;
    }

    if (!((x + y) % 2)){
        printf("-1\n");
        return 0;
    }

    direct(x, y);
    printf("%d\n", times);
    printf("%s\n", dir);
    return 0;
}