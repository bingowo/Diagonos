#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int p[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                p[i][j]=1;
            }
        }
        int pn;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&pn);
                p[i][j]=p[i][j]+pn;
                if((i-1)>=0)p[i-1][j]=p[i-1][j]+pn;
                if((j-1)>=0)p[i][j-1]=p[i][j-1]+pn;
                if((i+1)<=2)p[i+1][j]=p[i+1][j]+pn;
                if((j+1)<=2)p[i][j+1]=p[i][j+1]+pn;
            }
        }
        printf("case #%d:\n",t);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf("%d ",p[i][j]%2);
            }
            printf("\n");
        }
    }
    
}