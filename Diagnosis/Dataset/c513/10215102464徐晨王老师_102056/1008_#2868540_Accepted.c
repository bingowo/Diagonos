#include <stdio.h>
#include <stdlib.h>


int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
    int m,n;
    scanf("%d %d", &m, &n);
    int ret = 0;
    int hb;
    int num = 1;
    hb = m ^ n;
    for (int i = 0; i < 32; i++,num=num<<1) {
        if ((hb & num) == num) {
            ret++;
        }
    }
    printf("%d\n", ret);}
return 0;
}
