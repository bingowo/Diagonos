#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 160
char a[N][N];

struct data
{
    char c;
    int row;
    int col;
};

int main()
{
    char s[81];
    while(gets(s))
    {
        memset(a, ' ', sizeof(a));
        int len = strlen(s);
        int loc = 0,temp =0,min=0;

        struct data* D =(struct data*) malloc(len);
        for(int i = 0; i < len; i++)
        {
            D[i].c = s[i];
            D[i].col = i;
        }
        for(int i = 0; i < len - 1; i++)
        {
            if(s[i + 1] < s[i])
                temp--;
            else if(s[i + 1] > s[i])
                temp++;
            if(temp < min)
            {
                min = temp;
                loc = i + 1;
            }
        }
        D[loc].row = 0;
        for(int i = loc; i > 0; i--)
        {
            if(D[i - 1].c > D[i].c)
                D[i - 1].row = D[i].row + 1;
            else if(D[i - 1].c < D[i].c)
                D[i - 1].row = D[i].row - 1;
            else
                D[i - 1].row = D[i].row;
        }
        for(int i = loc; i < len - 1; i++)
        {
            if(D[i + 1].c > D[i].c)
                D[i + 1].row = D[i].row + 1;
            else if(D[i + 1].c < D[i].c)
                D[i + 1].row = D[i].row - 1;
            else
                D[i + 1].row = D[i].row;
        }

        for(int i = 0; i < len; i++)
            a[D[i].col][D[i].row] = D[i].c;


        int h = 0;
        for(int i = 0; i < len; i++)
        {
            if(D[i].row > h)
                h = D[i].row;
        }

        for(int i = h; i >= 0; i--)
        {
            for(int j = 0; j < len; j++) {
                printf("%c", a[j][i]);
            }printf("\n");
        }
    }
    return 0;
}
