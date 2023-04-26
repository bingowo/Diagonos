#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    int val;
    char dic;
}node;
void output(node **mat,int m,int n,int r,int c){
    if(r==0&&c==0)return;
    if(mat[r][c].dic=='D'){
        output(mat,m,n,r-1,c);
        putchar('D');
    }
    else {
        output(mat,m,n,r,c-1);
        putchar('R');
    }
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    node **mat=(int**)malloc(sizeof(node*)*m);
    for(int i=0;i<m;i++){
        mat[i]=(int*)malloc(sizeof(node)*n);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j].val);
        }
    }
    for(int i=1;i<m;i++){
        mat[i][0].val+=mat[i-1][0].val;
        mat[i][0].dic='D';
    }
    for(int i=1;i<n;i++){
        mat[0][i].val+=mat[0][i-1].val;
        mat[0][i-1].dic='R';
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(mat[i-1][j].val<mat[i][j-1].val){
                mat[i][j].val+=mat[i-1][j].val;
                mat[i][j].dic='D';
            }
            else {
                mat[i][j].val+=mat[i][j-1].val;
                mat[i][j].dic='R';
            }
        }
    }
    printf("%d\n",mat[m-1][n-1].val);
    output(mat,m,n,m-1,n-1);
    putchar('\n');
}