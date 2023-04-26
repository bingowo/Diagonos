#include<stdio.h>
#include<string.h>

const int ABO[4][4][4] = {
    {{1,0,0,1},{1,1,1,0},{1,1,1,1},{1,0,0,1}},
    {{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,0,1,0}},
    {{1,1,1,1},{1,1,1,0},{0,0,1,1},{0,0,1,1}},
    {{1,0,0,1},{1,0,1,0},{0,0,1,1},{0,0,0,1}}
};

int ans_ABO[4];

int read(){
    char s[10];
    scanf("%s", s);
    int flag = 0;
    if (!strcmp(s, "A")) flag = 1;
    else if (!strcmp(s, "B")) flag = 3;
    else if (!strcmp(s, "AB")) flag = 2;
    else if (!strcmp(s, "O")) flag = 4;
    else if (!strcmp(s, "?")) flag = 0;
    return flag;
}

void print(int x, int type){
    if (type == 1) printf("{");
    else if (type > 1) printf(",");
    if (x == 1) printf("A");
    if (x == 2) printf("AB");
    if (x == 3) printf("B");
    if (x == 4) printf("O");
}

void write(){
    int ABO = 0;
    for (int i = 0; i < 4; i++)
        ABO += ans_ABO[i];
    if (ABO == 0) printf("impossible");
    else{
        int cnt = 0;
        for (int i = 0; i < 4; i++)
            if (ans_ABO[i]){
                cnt++;
                print(i+1,cnt);
            }
        printf("}");
    }
}
int main(){

    int f, m, c;
    f = read(), m = read(), c = read();
    if (f == 0){
        int m1, c1;
        m1 = m - 1;
        c1 = c - 1;
        for (int i = 0; i < 4; i++)
            ans_ABO[i] = ABO[i][m1][c1];
    }
    if (m == 0){
        int f1, c1;
        f1 = f - 1;
        c1 = c - 1;
        for (int i = 0; i < 4; i++)
            ans_ABO[i] = ABO[f1][i][c1];
    }
    if (c == 0){
        int f1, m1;
        f1 = f - 1;
        m1 = m - 1;
        for (int i = 0; i < 4; i++)
            ans_ABO[i] = ABO[f1][m1][i];
    }
    if (f != 0) print(f, 0);
    else write();
    printf(" ");
    if (m != 0) print(m, 0);
    else write();
    printf(" ");
    if (c != 0) print(c, 0);
    else write();
    printf("\n");
    return 0;
}