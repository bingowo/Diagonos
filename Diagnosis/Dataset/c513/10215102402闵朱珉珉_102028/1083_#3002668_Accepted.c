#include <stdio.h>
int solve(int N)
{
    int result=0,t;
    for (t=1;t<=N;t++)
    {
        int temp=t;
        while (temp%5==0)
        {
            result++;
            temp=temp/5;
        }
    }
    return result;
}
int main()
{
    int T;
    scanf ("%d",&T);
    for (int q=0;q<T;q++)
    {
        int N;
        scanf ("%d",&N);
        printf("case #%d:\n%d\n",q,solve(N));
    }
}
