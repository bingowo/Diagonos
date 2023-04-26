#include<stdio.h>
#include<string.h>

typedef struct{
    int x, y;
}point;


int main(){
    char s[101]; scanf("%s", s);
    int op, len = strlen(s); scanf("%d", &op);
    for (int i = 0; i != op; i++){
        point ps[101];
        int aimx, aimy, x = 0, y = 0, right = 0, left = 0, up = 0, down = 0; scanf("%d%d", &aimx, &aimy);
        for (int i = 0; i != len; i++){
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;
            if (s[i] == 'L') x--;
            if (s[i] == 'R') x++;
            ps[i].x = x, ps[i].y = y;
            
            if (x > right) right = x;
            if (x < left) left = x;
            if (y > up) up = y;
            if (y < down) down = y;
        }

        while(!(aimx >= left && aimx <= right && aimy >= down && aimy <= up)){
            if (ps[len-1].x * aimx < 0) break;
            if (ps[len-1].y * aimy < 0) break;
            aimx -= ps[len-1].x;
            aimy -= ps[len-1].y;
        }

        if (aimx == 0 && aimy == 0){
            printf("Yes\n");
            continue;
        }
        int flag = 0;
        for (int i = 0; i != len; i++){
            if (aimx == ps[i].x && aimy == ps[i].y){
                printf("Yes\n"); flag = 1;
                break;
            }
        }
        if (!flag) printf("No\n");
    }
    return 0;
}