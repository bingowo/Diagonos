#include <stdio.h>

char table[] = "0123456789ABCDEF";

main()
{
    int N;
    int R;
    scanf("%d %d",&N,&R);
    char stack[100] = {};
    int m = 0;
    do
    {
        int k = N/R;
        if (N-k*R<0) k++;
        stack[m++] = table[N-k*R];
        N = k;
    } while (N!=0);
    while (m>0) printf("%c",stack[--m]);
    printf("\n");
    return 0;
}