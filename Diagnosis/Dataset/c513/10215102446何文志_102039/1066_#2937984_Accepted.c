#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cas = 0;
    scanf("%d",&cas);
    for(int i = 0;i<cas;i++){
        int n = 0,p = 0,m = 0,t = 0;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        if(t>n){printf("0\n");}
        else{
            int M[m+1][n];memset(M,0,(m+1)*n*sizeof(int));
            M[0][p-1] = 1;
            for(int j = 1;j<m+1;j++){
                M[j][0] = M[j-1][1];
                M[j][n-1] = M[j-1][n-2];
                for(int k = 1;k<n-1;k++){
                    M[j][k] = M[j-1][k-1]+M[j-1][k+1];
                }
            }
        //for(int j = 0;j<m+1;j++){
        //    for(int k = 0;k<n;k++){
        //        printf("%d ",M[j][k]);
        //    }
        //    printf("\n");
        //}
            int res = M[m][t-1];
            printf("%d\n",res);
        }
    }
    return 0;
}
