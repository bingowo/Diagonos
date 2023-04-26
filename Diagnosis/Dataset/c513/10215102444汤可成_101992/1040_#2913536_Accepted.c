#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans_ABO[4] = {0};  //表示i是否为可能的血型

int read()
{
    char s[10] = {0};
    scanf("%s", s);
    int flag = 0;
    if(strcmp(s, "A") == 0) flag = 1;
    else if(strcmp(s, "AB") == 0) flag = 2;
    else if(strcmp(s, "B") == 0) flag = 3;
    else if(strcmp(s, "O") == 0) flag = 4;
    else if(strcmp(s, "?") == 0) flag = 0;
    return flag;
}

void print(int x, int type)
{
    if(type == 1) printf("{");
    else if(type>1) printf(",");
    if(x == 1) printf("A");
    if(x == 2) printf("AB");
    if(x == 3) printf("B");
    if(x == 4) printf("O");
}

void write()
{
    int ABO = 0;
    int i = 0;
    for(i = 0; i<4; i++)
    {
        ABO += ans_ABO[i];
    }
    if(ABO==0) printf("impossible");
    else
    {
        int cnt = 0;
        for(i = 0; i<4; i++)
        {
            if(ans_ABO[i])
            {
                cnt++;
                print(i+1, cnt);
            }
        }
        printf("}");
    }
}


int main()
{
    //A - 0; AB - 1; B - 2; O - 3
    const int ABO[4][4][4] = {1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1};
    int f, m, c;
    f = read();
    m = read();
    c = read();
    if(f == 0)
    {
        int m1, c1;
        m1 = m -1;
        c1 = c-1;
        for(int i = 0; i<4; i++)
        {
            ans_ABO[i] = ABO[i][m1][c1];
        }
    }
    if(m == 0)
    {
        int f1, c1;
        f1 = f -1;
        c1 = c -1;
        for(int i = 0; i<4; i++)
        {
            ans_ABO[i] = ABO[f1][i][c1];
        }
    }
    if(c == 0)
    {
        int f1, m1;
        m1 = m -1;
        f1 = f-1;
        for(int i = 0; i<4; i++)
        {
            ans_ABO[i] = ABO[f1][m1][i];
        }
    }
    if(f!=0) print(f,0);
    else write();
    printf(" ");
    if(m!=0) print(m,0);
    else write();
    printf(" ");
    if(c!=0) print(c, 0);
    else write();
    printf("\n");

    return 0;
}
