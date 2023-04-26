#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int n,m;
char s[200];
int shortstep[201][201];
long long shortest(int**a,int x,int y){
    if (shortstep[x][y]!=-1) {return shortstep[x][y];}
    if (y==n-1&&x==m-1) {shortstep[x][y]=a[x][y];return a[x][y];}
    else if (y==n-1) shortstep[x][y]=shortest(a,x+1,y)+a[x][y];
    else if (x==m-1) shortstep[x][y]=shortest(a,x,y+1)+a[x][y];
    else if (shortest(a,x+1,y)>shortest(a,x,y+1)) shortstep[x][y]=shortest(a,x,y+1)+a[x][y];
    else shortstep[x][y]=shortest(a,x+1,y)+a[x][y];
    return shortstep[x][y];
}

int main()
{

    memset(shortstep,-1,sizeof(shortstep));
    scanf("%d%d",&m,&n);
    int**a=(int**)malloc(sizeof(int*)*m);
    for (int i=0;i<m;i++){
        a[i]=(int*)malloc(sizeof(int)*n);
        for (int j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    s[0]=0;
    long long  count=shortest(a,0,0);
    for (int i=0;i<m;i++)
        free(a[i]);
    free(a);
    printf("%ld\n",count);
    for (int i=0,j=0;i<m&&j<n;){
        if (shortstep[i+1][j]!=-1&&shortstep[i][j+1]!=-1)
            if (shortstep[i+1][j]<shortstep[i][j+1]) {printf("D");i++;}
            else {printf("R");j++;}
        else if (i==m-1&&j==n-1) i++;
        else if (shortstep[i+1][j]==-1) {printf("R");j++;}
        else {printf("D");i++;}
    }
    printf("\n");

//    printf("%s\n",s);
    return 0;
}
