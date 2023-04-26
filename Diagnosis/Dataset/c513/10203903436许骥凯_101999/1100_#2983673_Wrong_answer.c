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
        int aimx, aimy, x = 0, y = 0; scanf("%d%d", &aimx, &aimy);
        for (int i = 0; i != len; i++){
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;
            if (s[i] == 'L') x--;
            if (s[i] == 'R') x++;
            ps[i].x = x, ps[i].y = y;
        }

        if (ps[len-1].x == 0 && ps[len-1].y != 0){
            aimy %= ps[len-1].y;
        }
        else if (ps[len-1].x != 0 && ps[len-1].y == 0){
            aimx %= ps[len-1].x;
        }
        else if (ps[len-1].x != 0 && ps[len-1].y != 0){
            if (aimx == ps[len-1].x){
                aimx = 0; aimy -= ps[len-1].y;
            }
            else if (aimy == ps[len-1].y){
                aimy = 0; aimx -= ps[len-1].x;
            }
            else if (aimx != ps[len-1].x && aimy != ps[len-1].y){
                if (aimx <= aimy){
                    int div = aimx / ps[len-1].x;
                    aimx %= ps[len-1].x;
                    aimy -= ps[len-1].y * div;
                }
                else{
                    int div = aimy / ps[len-1].y;
                    aimy %= ps[len-1].y;
                    aimx -= ps[len-1].x * div;
                }
            }
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