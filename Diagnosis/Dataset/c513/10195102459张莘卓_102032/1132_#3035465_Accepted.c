#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n, r, a[32]={0}, cnt=0;
        scanf("%d %d",&n, &r);
        do {
            a[cnt++] = n % r;
        }while(n /= r);
        int sum = 0;
        while(cnt) sum += a[--cnt];
        do {
            a[cnt++] = sum % r;
        }while(sum /= r);
        printf("case #%d:\n",j);
        for(int i=cnt-1; i>=0; --i)
            if(a[i] < 10) printf("%d",a[i]);
            else printf("%c",a[i]+'A'-10);
        printf("\n");
    }
}
