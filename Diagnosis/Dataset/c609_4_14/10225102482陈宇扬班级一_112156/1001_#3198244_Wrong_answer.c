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
        if(num == 0) {putchar(table[0]);}
        do
        {
            int r = num % jz;
            a[k++] = table[r];
            num = num / jz;
        }while(num != 0);


        for(int i = T -1; i > 0; i--)
        {
            if(sign < 0){printf("-");}
            printf("%c", a[i]);
        }

        printf("\n");
    }
    return 0;
}
