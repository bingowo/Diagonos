#include <stdio.h>

int recur(int n)
{
    if (n==3) return 7;
    else if (n==2) return 4;
    else if (n==1) return 2;
    else if (n==0) return 0;
    else return 2*recur(n-1)-recur(n-2)+recur(n-3);
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==-1) break;
        printf("%d\n",recur(n));
    }
    return 0;
}