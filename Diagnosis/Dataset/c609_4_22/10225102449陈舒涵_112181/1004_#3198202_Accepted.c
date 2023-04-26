#include <stdio.h>
#include <string.h>

int main()
{
    int A, B, n = 0;
    char c;
    char a[33], b[33], s[] = "0123456789ABCDEF";
    scanf("%d %s %d", &A, &a, &B);
    for (int i = 0; i < strlen(a); i ++){
        c = a[i];
        if (c >='0' && c <= '9'){
            n = n * A + c - '0';
        }
        else{
            n = n * A + (c - 'A') % 32 + 10;
        }
    }
    if (n == 0){
        printf("0");
    }
    else{
        int num = 0, r;
        while (n > 0){
            r = n % B;
            b[num] = s[r];
            num ++;
            n /= B;
        }
        for (int j = num - 1; j >= 0; j --){
            printf("%c", b[j]);
        }
    }
    return 0;
}
