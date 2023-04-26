#include <stdio.h>

int count(int n)
{
    if(n < 0) return 0;
    else if(n == 0) return 1;
    else return count(n - 1) + count(n - 2) + count(n - 3) + count(n - 4) + count(n - 5);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        int N;
        scanf("%d",&N);
        printf("case #%d:\n%d\n",i,count(N));
    }
    return 0;
}
