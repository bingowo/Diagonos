#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 95

int main()
{
    int T,a,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        scanf("%d %d",&a,&n);
        int result[95]={0};
        result[0]=1;
        if(n==0) printf("1");
        else{
            for(int j=0;j<n;j++){
                int m,carry=0;
                for(m=0;m<N;m++){
                    int t=result[m]*a+carry;
                    result[m]=t%10;
                    carry=t/10;
                }
            }
            int k;
            for(k=N;k>=0;k--){
                if(result[k]!=0) break;
            }
            for(;k>=0;k--){
                printf("%d",result[k]);
            }
        }
        printf("\n");
    }
    return 0;
}
