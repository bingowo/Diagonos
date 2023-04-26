#include<stdio.h>

char dir[10000] = {0}; int times = 0;

void direct(long long int x, long long int y){
    if (x % 2 != 0){
        long long int e = x - 1, w = x + 1;
        y /= 2, e /= 2, w /= 2;
        if (y == 0 && e == 0){
            dir[times++] = 'E';
            return;
        }

        else if (y == 0 && w == 0){
            dir[times++] = 'W';
            return;
        }
        
        else if ((y + e) % 2 != 0){
            dir[times++] = 'E';
            direct(e, y);
        }

        else if ((y + w) % 2 != 0){
            dir[times++] = 'W';
            direct(w, y);
        }
    }

    if (y % 2){
        long long int n = y - 1, s = y + 1;
        x /= 2, n /= 2, s /= 2;
        if (x == 0 && n == 0){
            dir[times++] = 'N';
            return;
        } 
        
        else if (x == 0 && s == 0){
            dir[times++] = 'S';
            return;
        }

        else if ((x + n) % 2 != 0){
            dir[times++] = 'N';
            direct(x, n);
        }

        else if ((x + s) % 2 != 0){
            dir[times++] = 'S';
            direct(x, s);
        }
    }
}


int main(){
    long long int x, y; scanf("%lld%lld", &x, &y);
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