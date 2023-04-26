#include <stdio.h>
#include <string.h>
#include <math.h>

int cal(int n)
{
    int i, re = 1, R = 3;
    for (i = 0;i < n - 1;i++){
        re *= R;
    }
    return re;
}

int main()
{
    char I[31];
    int A[31], B[31], lena, lenb, i, j, a = 0, b1 = 0, b2, p;
    scanf("%s", I);
    j = 0;
    for (i = 0;I[i] != '.' && I[i] != '\0';i++){
        if (I[i] != '2'){
            A[j] = I[i] - '0';
        }else{
            A[j] = -1;
        }
        j += 1;
    }
    lena = i;
    if (i != strlen(I)){
        i += 1;
        for (j = 0;I[i] != '\0';i++){
            if (I[i] != '2'){
                B[j] = I[i] - '0';
            }else{
                B[j] = -1;
            }
            j += 1;
        }
        lenb = j;
        b2 = cal(lenb + 1);
        for (i = 0;i < lenb;i++){
            b1 += B[i] * cal(lenb - i);
        }
    }
    for (i = 0;i < lena;i++){
        a += A[i] * cal(lena - i);
    }
    if (b1 == 0){
        printf("%d", a);
        return 0;
    }
    for (p = 1;p <= b1;p++){
        if (b1 % p == 0 && b2 % p == 0){
            b1 /= p;
            b2 /= p;
            p = 1;
        }
    }
    if (a != 0){
        if (b1 < 0 && a > 0){
            a -= 1;
            b1 += b2;
        }else if (b1 > 0 && a < 0){
            a += 1;
            b1 = abs(b2 - b1);
        }
        printf("%d %d %d", a, b1, b2);
    }else{
        printf("%d %d", b1, b2);
    }
    return 0;
}