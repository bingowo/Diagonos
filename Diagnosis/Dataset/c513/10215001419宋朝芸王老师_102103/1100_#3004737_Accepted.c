#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100

typedef struct{
    int x, y;
}POINT;

POINT read(char s[], int i, POINT old){
    i--;
    POINT res = {0, 0};
    res.x = old.x, res.y = old.y;
    switch(s[i]){
        case('U'): res.y++; break;
        case('D'): res.y--; break;
        case('L'): res.x--; break;
        case('R'): res.x++; break;
    }
    return res;
}

int solve(int a, int b){
    if(a == 0 && b == 0) return -1;
    if(a != 0 && b == 0) return -2; // x/0
    if(a%b != 0 || a/b < 0) return -2;
    return a/b;
}

int main()
{
    char s[M+1] = {0};
    scanf("%s",s);
    int len = strlen(s);

    POINT pos[M+2] = {{0,0}};
    for(int i = 1; i <= len; i++)
        pos[i] = read(s,i,pos[i-1]);

    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int a,b,n1,n2;
        int flag = 0;
        scanf("%d%d",&a,&b);

        for(int k = 0; k <= len; k++){
            if(a == pos[k].x && b == pos[k].y){
                flag = 1;
                break;
            }

            n1 = solve(a-pos[k].x, pos[len].x);
            n2 = solve(b-pos[k].y, pos[len].y);
            if(n1 == -2 || n2 == -2) continue;
            if(n1 == -1 || n2 == -1 || n1 == n2){
                flag = 1;
                break;
            }
        }

        if(flag == 1) printf("Yes\n");
        else printf("No\n");

    }

    return 0;
}
