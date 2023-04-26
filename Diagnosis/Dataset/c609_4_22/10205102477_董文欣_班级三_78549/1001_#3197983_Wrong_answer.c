#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;//测试组数
    scanf("%d",&T);
    char a[100];

    for (int i = 0; i < T; i++)
    {
        int cnt = 0;
        int N,R;
        scanf("%d %d", &N,&R);
        if (N < 0) {N = -N; printf("-");}
        while (N)
        {
            if (N % R <= 10) a[cnt] = N % R + '0';
            else if (N % R > 10) a[cnt] = N % R - 10 + 'A';
            cnt++;
            N /= R;
        }
        for (int j = cnt - 1; j >= 0; j--) {
            printf("%c",a[j]);
        }

        printf("\n");
    }

    return 0;
}
