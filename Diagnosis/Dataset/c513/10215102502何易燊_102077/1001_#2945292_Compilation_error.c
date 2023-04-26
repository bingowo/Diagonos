#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    int n;
    scanf("%d",&n);
    int stack[50] = {};
    while (n--)
    {
        int N,R, index = 0;
        scanf("%d %d",&N,&R);
        int sign = (N<0)?-1:1;
        N = (N>0)? N:-N;
        char s[100] = {};
        itoa(N,s,R);
        if (sign==-1) printf("-");
        printf("%s\n");
    }
    return 0;
}