#include <stdio.h>
#include <string.h>

int main()
{
    char str[1001];
    char dest[1001];
    int T;
    scanf("%d",&T);
    for(int m = 0; m < T; m++)
    {
        int j,tmp;
        scanf("%s",str);
        int k=0;
        memset(dest,0,sizeof(dest));
        int len = strlen(str);
        for(int i = len - 1 ; i > 1 ; i--)
        {
            int num = str[i] - '0';
            for(j = 0 ; j < k || num != 0;j++)
            {
                tmp = 10 * num + (j<k ? dest[j]-'0' : 0);
                dest[j] = tmp / 8 + '0';
                num = tmp % 8;
            }
            k = j;
        }
        printf("case #%d:\n0.%s\n", m,dest);
    }
    return 0;
}