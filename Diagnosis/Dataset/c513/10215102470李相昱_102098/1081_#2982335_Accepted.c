#include <stdio.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int a,n;
        scanf("%d%d",&a,&n);
        int ret[101]={1,};
        int len=1;
        for(int t=0;t<n;t++){
            for(int j=0;j<len;j++){
                ret[j] = ret[j]*a;
            }
            int carry=0;
            int p=0;
            for(;p<len;p++){
                ret[p] = ret[p]+carry;
                carry = ret[p]/10;
                ret[p] = ret[p]%10;
            }
            if(carry){
                ret[p] = carry;
                p++;
            }
            len=p;
        }
        printf("case #%d:\n",i);
        for(int q=len-1;q>=0;q--){
            printf("%d",ret[q]);
        }
        printf("\n");
    }
    return 0;
}
