#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void) {
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int n,temp;
        scanf("%d",&n);
        int n1 =2,n2=5;
        int cnt1=0,cnt2=0;
        while (n/n1>0) {
            cnt1+=(n/n1);
            n1*=2;
        }
        while (n/n2>0) {
            cnt1+=(n/n2);
            n2*=5;
        }
        printf("case #%d:\n",i);
        printf("%d\n",cnt1>cnt2?cnt2:cnt1);
    }
    return 0;
}
