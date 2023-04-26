#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[20] = "0123456789ABCDEFGHIJ";
    int N = 0;
    int R = 0;
    scanf("%d %d", &N, &R);
    int n = N;
    int s = 0;
    int num = 0;
    while(n)
    {
        s = n/R;
        if((n - s*R)<0) s++;
        n = s;
        num++;
    }
    int i = 0;
    char* p = (char*)malloc(num+1);
    for(i = num-1; i>=0; i--)
    {
        s = N / R;
        if((N - s*R)<0)s++;
        p[i] = arr[N - s*R];
        N = s;
    }
    *(p+num) = 0;
    printf("%s", p);
    free(p);
    return 0;
}
