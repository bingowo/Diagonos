#include<stdio.h>

int main(){
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        int map[8] = {0};
        for (int i = 0; i != 9; i++)
            scanf("%d", &map[i]);
        int exp = 8;
        while(exp > -1 && map[8 - exp] == 0) exp--;
        int t = exp;
        for (int i = 8 - exp; i < 9; i++, t--){
            if (i == 8){
                if (map[i] != 0){
                    if (i == 8 - exp) printf("%d", map[i]);
                    else printf("%+d", map[i]);
                } 
                break;
            }
            if (map[i] == 0) continue;
            if (map[i] == 1){
                if(i == 8 - exp){
                    if(t == 1) printf("x");
                    else printf("x^%d", t);
                }
                else{
                    if (t == 1) printf("+x");
                    else printf("+x^%d", t);
                }
            }
            else if (map[i] == -1){
                if (t == 1) printf("-x");
                else printf("-x^%d", t);
            }
            else{
                if (t == 1) printf("%+dx", map[i]);
                else printf("%+dx^%d", map[i], t);
            }
        }
        if (exp == -1) printf("0");
        printf("\n");
    }
}