#include <stdio.h>

main()
{
    int n;
    scanf("%d",&n);
    int stack[50] = {};
    while (n--)
    {
        int N,R, index = 0;
        scanf("%d %d",&N,&R);
        if (N<0) {printf("-"); N = -N;}
        do
        {
            int mod = N % R;
            N /= R;
            if (mod<10) stack[index++] = mod + '0';
            else stack[index++] = mod + 'A' - 10;
        } while (N);
        while (index>=0) printf("%c",stack[--index]); 
        printf("\n")
    }
    return 0;
}