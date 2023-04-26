#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define len 1000


int main(void) {
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int a,n,idx;
        scanf("%d %d",&a,&n);
        int out[len]={0};
        out[len-1]= 1;
        for (int i=0; i<n; i++) {
            for (int k=len-1; k>1; k--) {
                out[k]*=a;
            }
            for (int k=len-1; k>1; k--) {
                int carry;
                carry = out[k]/10;
                out[k]%=10;
                out[k-1]+=carry;
            }
            printf("case #%d:\n",i);
            for (idx=0; out[idx]==0; idx++);
            for (; idx<len; idx++) {
                printf("%d",out[idx]);
            }
            printf("\n");
        }
        printf("case #%d:\n",i);
        for (idx=0; out[idx]==0; idx++);
        for (; idx<len; idx++) {
            printf("%d",out[idx]);
        }
        printf("\n");
    }
    return 0;
}
