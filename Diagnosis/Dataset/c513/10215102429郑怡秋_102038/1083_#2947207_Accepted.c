#include <stdio.h>


int GetN_1(int n)
{
    if (n < 5)
    {
        return 0;
    }
    else
    {
        return (n / 5 + GetN_1(n / 5));
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        printf("case #%d:\n%d\n",i,GetN_1(m));
    }
    return 0;
}