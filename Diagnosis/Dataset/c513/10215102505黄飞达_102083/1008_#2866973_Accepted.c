#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int func(int x, int y){
    int count = 0;
    for (int i = 0; i < 32; i++){
        if ((x&1) != (y&1)){
            count++;
        }
        x>>=1;
        y>>=1;
    }
    return count;
}

int main(){
    int t, x, y;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        scanf("%d %d", &x, &y);
        printf("%d\n", func(x, y));
    }
    return 0;
}