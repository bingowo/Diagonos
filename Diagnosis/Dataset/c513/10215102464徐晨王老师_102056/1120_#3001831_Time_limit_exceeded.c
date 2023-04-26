#include <stdio.h>
#include <stdlib.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int r,c,n,k;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        int p[r][c];
        for(int i=0;i<t;i++){
            for(int j=0;j<c;j++){
                p[i][j]=0;
            }
        }
        for(int N=0;N<n;N++){
            int a,b;
            scanf("%d%d",&a,&b);
            p[a][b]=1;
        }
        int num=0;
        for(int len1=1;len1<=r;len1++){
            for(int len2=1;len2<=c;len2++){
                int sum=0;
                for(int i=len1;i<=(r-len1);i++){
                    for(int j=len2;i<=(c-len2);j++){
                        sum=sum+p[i][j];
                    }
                }
                if(sum>=n)num++;
            }
        }
        printf("case #%d:\n%d\n",t,num);
    }
}