#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char s[8][9];
} BP;

int cmp(const void* a,const void* b)
{
    char* pa=(char *)a; char* pb=(char *)b;
    for (int i=0;i<8;i++)
    {
        if (pa[i]>pb[i]) return 1;
        if (pa[i]<pb[i]) return -1;
    }

}

int btoi(char* s)
{
    int n=0;
    for (int i=0;i<8;i++)
    {
        n=2*(n+s[i]-'0');
    }
    n=n/2;

    return n;
}

int main()
{
    int W,H;
    scanf("%d %d",&W,&H);
    int** arr=(int**)malloc(H*sizeof(int*));
    for (int i=0;i<H;i++)
        arr[i]=(int*)malloc(W*sizeof(int));
    for (int i=0;i<H;i++)
        for (int j=0;j<W;j++)
            scanf("%d",&arr[i][j]);
    BP** arr2=(BP**)calloc((H-2),sizeof(BP*));
    for (int i=0;i<H-2;i++)
        arr2[i]=(BP*)calloc((W-2),sizeof(BP));
    for (int i=1;i<H-1;i++)
        for (int j=1;j<W-1;j++)
        {
            arr2[i-1][j-1].s[0][0]=(arr[i-1][j-1]>=arr[i][j])?'1':'0';
            arr2[i-1][j-1].s[0][1]=(arr[i-1][j]>=arr[i][j])?'1':'0';
            arr2[i-1][j-1].s[0][2]=(arr[i-1][j+1]>=arr[i][j])?'1':'0';
            arr2[i-1][j-1].s[0][3]=(arr[i][j+1]>=arr[i][j])?'1':'0';
            arr2[i-1][j-1].s[0][4]=(arr[i+1][j+1]>=arr[i][j])?'1':'0';
            arr2[i-1][j-1].s[0][5]=(arr[i+1][j]>=arr[i][j])?'1':'0';
            arr2[i-1][j-1].s[0][6]=(arr[i+1][j-1]>=arr[i][j])?'1':'0';
            arr2[i-1][j-1].s[0][7]=(arr[i][j-1]>=arr[i][j])?'1':'0';
        }
     for (int i=0;i<H-2;i++)
        for (int j=0;j<W-2;j++)
        {
            for (int k=1;k<8;k++)
            {
                for (int m=1;m<=7;m++)
                {
                    arr2[i][j].s[k][m-1]=arr2[i][j].s[k-1][m];
                }
                arr2[i][j].s[k][7]=arr2[i][j].s[k-1][0];
            }
        }
    for (int i=0;i<H-2;i++)
        for (int j=0;j<W-2;j++)
        {
            qsort(arr2[i][j].s,8,sizeof(arr2[i][j].s[0]),cmp);
            printf("%d%c",btoi(arr2[i][j].s[0]),(j==W-3)?'\n':' ');
        }



    return 0;
}
