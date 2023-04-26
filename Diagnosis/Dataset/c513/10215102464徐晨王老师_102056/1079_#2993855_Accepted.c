#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a,const void *b){
long int x=*(long int*)a;
long int y=*(long int*)b;
return x>y;
}


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
        for(len=0;len<n;len++){
            for(int i=0;i<n;i++){
                pp[index]=0;
                if((i+len)<n){
                    for(int j=i;j<=(i+len);j++){
                        pp[index]=pp[index]+p[j];
                    }
                    index++;
                }
            }
        }
        qsort(pp,n*(n+1)/2,sizeof(pp[0]),cmp);
        printf("case #%d:\n",t);
        for(int i=0;i<m;i++){
            int L,U;
            scanf("%d%d",&L,&U);
            long int sum=0;
            for(int j=L;j<=U;j++){
                sum=sum+pp[j-1];
            }
            printf("%ld\n",sum);
        }
    }
}
