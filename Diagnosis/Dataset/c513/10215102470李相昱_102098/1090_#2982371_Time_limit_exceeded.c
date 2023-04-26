#include <stdio.h>
#include <stdlib.h>
int main() {
    int N;
    while(scanf("%d",&N)&&N!=0){
        int * ret =(int *)malloc(800000001*sizeof(int));
        ret[0]=N;
        int len=1;
        for(int i=0;i<N-1;i++){
            for(int j=0;j<len;j++){
                ret[j] = ret[j]*N;
            }
            int carry=0;
            int m=0;
            for(;m<len||carry>0;m++){
                ret[m] = ret[m]+carry;
                carry = ret[m]/10;
                ret[m] = ret[m]%10;
            }
            len = m;
        }
        printf("%d\n",ret[len-1]);
    }
    return 0;
}
