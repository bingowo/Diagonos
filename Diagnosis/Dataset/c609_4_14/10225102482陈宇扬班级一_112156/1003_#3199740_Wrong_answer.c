#include <stdio.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        scanf("%d", &n);

        int sum = 0;
        int ans[100];
        do
        {
            ans[sum++] = n % 2333;
        } while (n /= 2333);

        for(int j = sum -1; j >= 0; j--)
            printf("%d ", ans[j]);
        printf("\n");
    }
    return 0;
}
