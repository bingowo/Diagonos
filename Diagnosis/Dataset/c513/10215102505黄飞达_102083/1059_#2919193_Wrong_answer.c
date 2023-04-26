#include<stdio.h>

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    int high[1005] = {0};
    for (int i = 0; i < n; i++) scanf("%d", &high[i]);
    int capacity[1005] = {0};
    for (int i = 0; i < n; i++){
        for (int j = 1; j+high[i]<1001; j++){
            capacity[j+high[i]] += j;
        }
    }
    int res[3] = {0};
    for (int i = 0; i < 1001; i++){
        if (capacity[i] <= s && s <= capacity[i+1]){
            res[0] = i;
            s -= capacity[i];
            res[1] = s;
            res[2] = capacity[i+1]-capacity[i];
            break;
        }
    }
    if (res[1]==0) printf("%d\n", res[0]);
    else {
        if (res[1]==res[2]) printf("%d\n", res[0]+1);
        else printf("%d+%d/%d\n", res[0], res[1], res[2]);
    }
    return 0;
}