#include <stdio.h>
#include <stdlib.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int r,c,n,k;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        int p[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                p[i][j]=0;
            }
        }
        for(int N=0;N<n;N++){
            int a,b;
            scanf("%d%d",&a,&b);
            p[a-1][b-1]=1;
        }
        int num=0;
        for(int len1=1;len1<=r;len1++){
            for(int len2=1;len2<=c;len2++){
                for(int i=0;i<=(r-len1);i++){
                    for(int j=0;j<=(c-len2);j++){
                        int sum=0;
                        for(int s=i;s<(i+len1);s++){
                            for(int l=j;l<(j+len2);l++){
                               sum=sum+p[s][l];
                            }
                        }
                        if(sum>=k)num++;
                    }
                }
            }
        }
        printf("case #%d:\n%d\n",t,num);
    }
}
