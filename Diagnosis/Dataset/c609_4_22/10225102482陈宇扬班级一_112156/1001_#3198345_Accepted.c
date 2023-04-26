#include <stdio.h>

int main()
{
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int num, jz;
        scanf("%d%d", &num, &jz);
        int k = 0, a[33] = {0}, sign = 1;
        if(num < 0) {sign = -1, num = -num;}
        else if(num == 0) {putchar(table[0]);}

        do
        {
            int r = num % jz;
            a[k++] = table[r];
            num = num / jz;
        }while(num != 0);

        if(sign < 0){printf("-");}
        for(int i = k - 1; i >= 0; i--)
            printf("%c", a[i]);
        printf("\n");
    }
    return 0;
}

