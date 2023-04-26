#include<stdio.h>

typedef struct{
    int a, b;
}pair;



int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        pair arrp[100]; int table[15000] = {0}, idx = 0, cnt[101][2] = {0};
        int ordv; scanf("%d", &ordv);
        for (int i = 0; i != ordv; i++){
            int ta, tb; scanf("%d%d", &ta, &tb);
            if (table[ta * 100 + tb] != 1){
                table[ta*100+tb] = 1;
                cnt[ta][0]++; // cnt[][0]: out
                cnt[tb][1]++; // cnt[][1]: in
            }
        }

        int flag = 0;
        for (int i = 1; i != 101; i++){
            if (cnt[i][0] >= 2 || cnt[i][0] >= 1 && cnt[i][1] >= 1){
                printf("Poor dxw!\n");
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        printf("Lucky dxw!\n");
    }
    return 0;
}