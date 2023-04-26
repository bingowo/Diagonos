#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const short N = 150;
char a[N][N];
typedef struct 
{
    char c;
    int row;
    int col;
}data;

int main()
{
    char s[100];
    while(scanf("%s",s))
    {
        memset(a, ' ', sizeof(a));
        int len = strlen(s);
        int min;
        int loc = 0;
        int temp = min = 0;

        data* D = (data*)malloc(sizeof(data)*len);//new data[len];
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
            for(int j = 0; j < len; j++)
            {    printf("%c",a[j][i]);}//cout << a[j][i];}
            printf("\n");//cout << endl;
        }
     free(D);      
    }
    return 0;
}
