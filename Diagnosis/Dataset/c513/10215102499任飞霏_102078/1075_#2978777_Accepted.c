#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200

typedef struct
{
    int d;
    char c;
}Elem;

void shortestpath(Elem A[][SIZE],int m,int n)
{
    int i,j;
    for(i=1;i<m;i++){
        A[i][0].d+=A[i-1][0].d;
        A[i][0].c='D';
    }
    for(i=1;i<n;i++){
        A[0][i].d+=A[0][i-1].d;
        A[0][i].c='R';
    }
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(A[i-1][j].d<A[i][j-1].d){
                A[i][j].d+=A[i-1][j].d;
                A[i][j].c='D';
            }
            else{
                A[i][j].d+=A[i][j-1].d;
                A[i][j].c='R';
            }
        }
    }
}

void outpath(Elem A[][SIZE],int r,int c)
{
    if(r==0&&c==0)return;
    if(A[r][c].c=='D'){
        outpath(A,r-1,c);
        putchar('D');
    }
    else{
        outpath(A,r,c-1);
        putchar('R');
    }
}

int main()
{
    Elem A[SIZE][SIZE];
    int m,n;
    int i,j;

    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j].d);
            A[i][j].c=0;
        }
    }
        shortestpath(A,m,n);
        printf("%d\n",A[m-1][n-1].d);
        outpath(A,m-1,n-1);
        putchar('\n');
    return 0;
}
