#include <stdio.h>

int main()
{
    char I[120];
    int n, p, i, j, k, l, a;
    scanf("%d\n", &n);
    for (i = 0;i < n;i++){
        p = 0;
        l = 0;
        gets(I);
        for (k = 0;I[k] != '\0';k++){
            for (j = 0;j < 8;j++){
                    p += I[k] % 2;
                    l += 1;
                    I[k] /= 2;
            }
        }
        do
        {
            for (a = 1;a <= p;a++){
                if (p % a == 0 && l % a == 0){
                    p /= a;
                    l /= a;
                }
            }
        }while(a <= p);
        printf("%d/%d\n", p, l);
    }
    return 0;
}