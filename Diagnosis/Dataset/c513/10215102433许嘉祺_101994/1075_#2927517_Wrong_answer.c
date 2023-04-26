#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int n,m;
char s[200];
long long shortest(int**a,int x,int y){

    if (x==m-1){
            long long step=0;
        for (int i=y;i<n;i++)
            step+=a[x][i];
    return step;
        }
    if (y==n-1){
        long long step=0;
        for (int i=x;i<m;i++)
            step+=a[i][y];
        return step;
    }
    long long shortdown=shortest(a,x+1,y);
    long long shortright=shortest(a,x,y+1);
    if (shortdown<shortright) {
            if (x+1==m-1)
            for (int i=y;i<n;i++)
                
            sprintf(s,"%c%s",'D',s);
            return shortdown+a[x][y];
    }
    else {
        sprintf(s,"%c%s",'R',s);
        return shortright+a[x][y];
    }
}

int main()
{


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
    
//    printf("%s\n",s);
    return 0;
}