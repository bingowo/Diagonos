#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char t[100];
    scanf("0x%s", s);
    int k = 0;
    for (int i = 0; i < strlen(s); i++) {
        int d;
        if (s[i] >= 'A')
            d = s[i] - 'A' + 10;
        else
            d = s[i] - '0';
        unsigned int flag = 0x8;
        while (flag){
            if (d & flag)
                t[k++] = '1';
            else
                t[k++] = '0';
            flag >>= 1;
        }
    }

    // for (int i = 0; i < k; i++)
    //     printf("%c", t[i]);
    // printf("\n");

    long long int qr = 0, qi = 0;
    long long int a,b;
    for (int i = 0; i < k; i++) {
        int r = t[i] - '0';
        // printf("qr = %lld, qi = %lld, r = %d\n", qr,qi,r);
        a = -qr-qi+r;
        b = qr-qi;
        qr = a;
        qi = b;
        // printf("a = %lld, b = %lld\n", a, b);
    }

    //output
    if (qi == 0)
        printf("%lld", qr);
    else{
        if (qr != 0){
            printf("%lld", qr);
            if (qi > 0)
                printf("+");
        }
        if (qi == 1)
            printf("i");
        else if (qi == -1)
            printf("-i");
        else
            printf("%lldi", qi);
    }


    return 0;
}