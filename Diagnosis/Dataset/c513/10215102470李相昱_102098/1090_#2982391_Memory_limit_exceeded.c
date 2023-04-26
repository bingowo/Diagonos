#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int N;
    int * ret =(int *)malloc(100000001*sizeof(int));
    while(scanf("%d",&N)&&N!=0){
        memset(ret,0,100000001*sizeof(int));
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
                carry = ret[m]/100000000;
                ret[m] = ret[m]%100000000;
            }
            len = m;
        }
        int cnt = 100000000;
        while(!(ret[len-1]/cnt)){
            cnt= cnt/10;
        }
        printf("%d\n",ret[len-1]/cnt);
    }
    free(ret);
    return 0;
}
