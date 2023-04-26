#include<stdio.h>
#include<stdlib.h>
int main()
{
    unsigned int T,n,out;
    unsigned int b,b1;
    scanf("%u",&T);

    for(int i = 0;i < T;i++){
        scanf("%u",&n);
        out = 1;
        b1 = n%2;
        n /= 2;
        b = n%2;
        while(b != b1 && n > 0 && out++){
            n /= 2;
            b1 = b;
            b = n%2;
        }
        printf("case #%u:\n",i);
        printf("%u\n",out);
    }
    return 0;
}