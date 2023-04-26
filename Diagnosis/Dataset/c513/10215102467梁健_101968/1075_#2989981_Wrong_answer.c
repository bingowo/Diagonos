#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>



int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int M[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&M[i][j]);
    long res=0;
    int x=0,y=0;
    char s[1000];
    int k=0;
    while(x!=m-1||y!=n-1){
        res+=M[x][y];
        if(x!=m-1&&y!=n-1){
            if(M[x+1][y]>M[x][y+1]){
                s[k++]='R';
                //printf("(%d,%d)%d %d\n",x,y,M[x][y],res);
                y++;
            }
            else{
                s[k++]='D';
                //printf("(%d,%d)%d %d\n",x,y,M[x][y],res);
                x++;
            }
        }
        else if(x==m-1){
            s[k++]='R';
            //printf("(%d,%d)%d %d\n",x,y,M[x][y],res);
            y++;
        }
        else if(y==n-1){
            s[k++]='D';
            //printf("(%d,%d)%d %d\n",x,y,M[x][y],res);
            x++;
        }
    }
    //printf("%d %d\n",x,y);
    s[k]=0;
    res+=M[x][y];
    printf("%ld\n",res);
    printf("%s",s);
    return 0;
}
