#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i;
    scanf("%d", &i);
    char ans[16][50000];
    ans[0][0] = '0';
    ans[0][1] = '\0';
    for (int j = 1; j < 16; j++)
    {
        int l = strlen(ans[j - 1]);
        for (int k = 0; k < l; k++)
        {
            if (ans[j - 1][k] == '0')
            {
                ans[j][k] = '0';
                ans[j][k + l] = '1';
            }
            else
            {
                ans[j][k] = '1';
                ans[j][k + l] = '0';
            }
        }
    }
    printf("%s\n", ans[i]);
    return 0;
}