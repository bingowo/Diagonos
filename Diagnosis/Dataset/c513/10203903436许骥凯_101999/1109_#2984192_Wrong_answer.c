#include<stdio.h>

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i < pro; i++){
        printf("case #%d:\n", i);
        int map[9] = {0};
        for (int j = 0; j != 9; j++)
            scanf("%d", &map[j]);
        int cnt = 0;
        for (int j = 0; j != 9; j++)
            if (map[j] == 0) cnt++;
        if (cnt == 9){
            printf("0\n");
            continue;
        }
        int exp = 8;
        while(exp > -1 && map[8 - exp] == 0) exp--;
        int t = exp;
        for (int j = 8 - exp; j < 9; j++, t--){
            if (j == 8){
                if (map[j] != 0){
                    if (j == 8 - exp) printf("%d", map[j]);
                    else printf("%+d", map[j]);
                } 
                break;
            }
            if (map[j] == 0) continue;
            if (map[j] == 1){
                if(j == 8 - exp){
                    if(t == 1) printf("x");
                    else printf("x^%d", t);
                }
                else{
                    if (t == 1) printf("+x");
                    else printf("+x^%d", t);
                }
            }
            else if (map[j] == -1){
                if (t == 1) printf("-x");
                else printf("-x^%d", t);
            }
            else{
                if (i == 8 - exp){
                    if (t == 1) printf("%dx", map[j]);
                    else printf("%dx^%d", map[j], t);
                }
                else if (t == 1) printf("%+dx", map[j]);
                else printf("%+dx^%d", map[j], t);
            }
        }
        printf("\n");
    }
    return 0;
}