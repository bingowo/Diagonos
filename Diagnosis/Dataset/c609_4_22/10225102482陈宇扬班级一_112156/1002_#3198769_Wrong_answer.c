#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);
        int k = 0, a[100];
        int cnt = 0;
        do
        {
            int r = n % 2;
            a[k++] = r;
            n = n / 2;
        }while(n);

        for(int j = k; j > 0; j--)
        {
            if(a[j] != a[j-1]) cnt++;

        }
        printf("case #%d:\n%d", i, cnt);
        printf("\n");
    }
    return 0;
}
