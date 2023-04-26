#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, num;
    scanf("%d", &n);
    int flag=1;
    int n1, n2 = 0;
    while (flag)
    {
        n1 = n;
        n2 = 0;
        while (n)
        {
            n2 = n2 * 10 + n % 10;
            n = n / 10;
        }
        if(n1!=n2)
        {
            num++;
            n = n1+n2;
            flag = 1;
        }
        else flag=0;
    }
    printf("%d %d", num, n1);
    return 0;
}