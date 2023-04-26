#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    int n,r;//整数,进制数;
    char a[100];
    
    while(t--)
    {
        int i = 0;
        scanf("%d %d",&n,&r);
        if(n < 0)
        {
            printf("-");
            n = -n;
        }
        while(n)
        {
            if(n % r < 10)
                a[i] = n % r + '0';
            else if(n % r >= 10)
                a[i] = n % r - 10 + 'A';
            i++;
            n = n/r;
        }
        for(int j = i - 1; j >= 0; j--)
        {
            printf("%c",a[j]);
        }
        printf("\n");
    }

    return 0;
}