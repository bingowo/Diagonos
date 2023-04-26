#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n,m;
        scanf("%d%d",&n,&m);
        int p[n];
        for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
        }
        long int pp[n*(n+1)/2];
        int index=0;
        int len=0;
        for(int len=0;len<n;len++){
            for(int i=0;i<n;i++){
                for(int j=i;j<=(i+len);j++){
                    if(j<n){
                        pp[index]=pp[index]+p[j];
                    }
                }
            index++;
            }
        }
        for(int i=0;i<m;i++){
            int L,U;
        }
        printf("case #%d:\n",t);
    }
}