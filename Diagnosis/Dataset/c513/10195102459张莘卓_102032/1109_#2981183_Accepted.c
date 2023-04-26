#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d ",&T);
    for(int j=0; j<T; ++j) {
        int a[9] = {0},b[9] = {0}, k, cnt = 0;
        for(int i=8; i>=0; --i) {
            scanf("%d",&k);
            if(k) {
                a[cnt] = i;
                b[cnt++] = k;
            }
        }
        printf("case #%d:\n",j);
        if(cnt == 0) printf("0");
        else {
            for(int i=0; i<cnt; ++i) {
                if(i) printf("%c",b[i]>0?'+':'-');
                else if(b[i] < 0) printf("-");
                b[i] = abs(b[i]);
                if(b[i]!=1 || a[i]==0) printf("%d",b[i]);
                if(a[i] == 1) printf("x");
                else if(a[i]) printf("x^%d",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
