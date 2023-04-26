#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m = 0;
    scanf("%d", &m);
    getchar();
    int n = 0;
    int arr[501] = {0};
    for(int i = 0; i<m; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = m; i<500; i++)
    {
        arr[i] = -1;
    }
    scanf("%d", &n);
    int b[501] = {0};
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n-1-i; j++)
        {
            int p = b[j], q = b[j+1];
            int dex1 = 501, dex2 = 501;
            for(int g = 0; g<m; g++)
            {
                if(arr[g] == p) dex1 = g;
                if(arr[g] == q) dex2 = g;
            }
            if(dex1 > dex2)
            {
                b[j+1] = p;
                b[j] = q;
            }
            else if(dex1 == dex2)
            {
                if(p>q)
                {
                    b[j+1] = p;
                    b[j] = q;
                }
            }
        }
    }
    for(int i = 0; i<n; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}
