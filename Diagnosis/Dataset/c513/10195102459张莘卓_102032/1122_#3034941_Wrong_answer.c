#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int a[100]={0}, cnt=0, n;
        scanf("%d",&n);
        do{
            a[cnt++] = n % 2333;
            n /= 2333;
        }while(n);
        for(; cnt; --cnt) {
            printf("%d%s",a[cnt-1],cnt-1?" ":"\n");
        }
    }
    return 0;
}
