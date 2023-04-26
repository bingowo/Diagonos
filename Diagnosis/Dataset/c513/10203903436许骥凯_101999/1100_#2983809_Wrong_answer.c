#include<stdio.h>
#include<string.h>

typedef struct{
    int x, y;
}point;


int main(){
    char s[101]; scanf("%s", s);
    int op, len = strlen(s); scanf("%d", &op);
    int x = 0, y = 0, right = 0, left = 0, up = 0, down = 0;
    point ps[101];

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
    for (int i = 0; i != op; i++){
        int endx = ps[len-1].x, endy = ps[len-1].y;
        int aimx, aimy; scanf("%d%d", &aimx, &aimy);
        int flag = 1;
        if (aimx == 0 && aimy == 0){
            printf("Yes\n");
            continue;
        }
        for (int j = 0; j != len; j++){
            int jde1 = aimx - ps[j].x, jde2 = aimy - ps[j].y;
            if (jde1 == 0 && jde2 == 0){
                printf("Yes\n"); flag = 0; break;

            }
            else{
                if (endx == 0 && endy != 0){
                    if (jde1 == 0 && jde2 % endy == 0 && jde2 / endy > 0){
                        printf("Yes\n"); flag = 0; break;
                    }
                }
                else if (endy == 0 && endx != 0){
                    if (jde2 == 0 && jde1 % endx == 0 && jde1 / endx > 0){
                        printf("Yes\n"); flag = 0; break;
                    }
                }
                else if (endx != 0 && endy != 0){
                    if (jde1 % endx == 0 && jde1 / endx > 0 && jde2 % endy == 0 && jde2 / endy > 0){
                        printf("Yes\n"); flag = 0; break;
                    }
                }
            }
        }
        if (flag) printf("No\n");
    }
}