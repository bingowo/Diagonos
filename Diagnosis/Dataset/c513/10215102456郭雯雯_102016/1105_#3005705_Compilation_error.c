#include<stdio.h>

int lbp(int *l;int m;int n){
    int num[8],k=0,a=l[m][n];
    num[0]=(int)(l[m-1][n-1]>=a);
}

int main(){
    int w,h;
    scanf("%d %d",&w,&h);
    int num[h][w],ans[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            scanf("%d",&num[i][j]);
            ans[i][j]=0;
        }
    for(int i=1;i<h-1;i++)
        for(int j=1;j<w-1;j++)ans[i][j]=lbp(num,i,j);
    for(int i=1;i<h-1;i++)
        for(int j=1;j<w-1;j++){
            printf("%d",ans[i][j]);
            if(j==w-2)printf("\n");
            else printf(" ");
        }
    return 0;
}