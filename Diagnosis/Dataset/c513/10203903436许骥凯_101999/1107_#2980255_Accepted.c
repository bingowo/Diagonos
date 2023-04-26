#include<stdio.h>
#include<string.h>
void change(int light[3][3], int loc){
    int y = loc % 3;
    int x = loc / 3;
    if (light[x][y]) light[x][y] = 0;
    else light[x][y] = 1;
    
    if (x >= 1 && light[x-1][y]) light[x-1][y] = 0;
    else if (x >= 1) light[x-1][y] = 1;
    
    if ((x < 2 && light[x+1][y])) light[x+1][y] = 0;
    else if (x < 2) light[x+1][y] = 1;
    
    if (y >= 1 && light[x][y-1]) light[x][y-1] = 0;
    else if (y >= 1) light[x][y-1] = 1;
    
    if (y < 2 && light[x][y+1]) light[x][y+1] = 0;
    else if (y < 2) light[x][y+1] = 1;
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int light[3][3]; 
        for (int i = 0; i != 3; i++)
            for (int j = 0; j != 3; j++)
                light[i][j] = 1;
        for (int j = 0; j != 9; j++){
            int op; scanf("%d", &op);
            for (int k = 0; k < op; k++)
                change(light, j);
        }
        printf("case #%d:\n", i);
        for (int j = 0; j != 3; j++)
            for (int k = 0; k != 3; k++)
                printf("%d%c", light[j][k], k == 2? '\n': ' ');
    }
    return 0;
}