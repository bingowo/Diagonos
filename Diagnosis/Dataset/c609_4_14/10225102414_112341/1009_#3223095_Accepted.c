#include <stdio.h>
#include <string.h>


int main()
{
    char I[121];
    int n, p, i, j, k, a, l;
    scanf("%d\n", &n);
    for (i = 0;i < n;i++){
        p = 0;
        gets(I);
        l = strlen(I) * 8;
        for (k = 0;k < l / 8;k++){
            for (j = 0;j < 8;j++){
                    p += I[k] & 1;
                    I[k] >>= 1;
            }
        }
        do
        {
            for (a = 1;a <= p;a++){
                if (p % a == 0 && l % a == 0){
                    p /= a;
                    l /= a;
                    a = 1;
                }
            }
        }while(a <= p);
        printf("%d/%d\n", p, l);
    }
    return 0;
}