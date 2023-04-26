#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inttoHEX(int n, char I[])
{
    char L[16] = "0123456789abcdef";
    int i;
    if (n < 0){
        n = 0 - (n + 1);
        for (i = 0;n != 0;n /= 16){
            I[i] = L[15 - n % 16];
            i += 1;
        }
    }else{
        for (i = 0;n != 0;n /= 16){
                I[i] = L[n % 16];
                i += 1;
        }
    }
}

void inttoBIN(int n, char I[])
{
    int i;
    if (n < 0){
        n = 0 - (n + 1);
        for (i = 0;n != 0;n /= 2){
            if (n % 2 == 1){
                I[i] = '0';
            }else{
                I[i] = '1';
            }
            i += 1;
        }
    }else{
        for (i = 0;n != 0;n /= 2){
            if (n % 2 == 1){
                I[i] = '1';
            }else{
                I[i] = '0';
            }
            i += 1;
        }
    }
}

void doubletoHEX(double N, char D[])
{
    int p, n = N, i, j, z, w, b;
    double m = N - n;
    char I[100], P[100], M[100], C[64], L[16] = "0123456789abcdef";
    memset(I, '\0', 100);memset(P, '\0', 100);memset(M, '\0', 100);memset(C, '\0', 64);
    inttoBIN(n, I);
    for (i = 0;m != 0;i++){
        z = m * 2;
        if (z == 1){
            M[i] = '1';
        }else{
            M[i] = '0';
        }
        m = m * 2 - z;
    }
    w = 0;
    if (strlen(I) == 0 && strlen(M) != 0){
        for (i = 0;M[i] != '1';i++);
        p = 1023 - (i + 1);
        w = i + 1;
    }
    else if (strlen(I) != 0){
        p = strlen(I) - 1 + 1023;
        I[strlen(I) - 1] = '\0';
    }else if (N != 0){
        p = 1023;
    }else{
        p = 0;
    }
    inttoBIN(p, P);
    if (N < 0){
        C[0] = '1';
    }else{
        C[0] = '0';
    }
    i = 1;
    for (j = 10;j >= 0;j--){
        if (P[j] == '\0'){
            C[i] = '0';
        }else{
            C[i] = P[j];
        }
        i += 1;
    }
    for (j = strlen(I) - 1;j >= 0;j--){
        if (i == 63){
            i += 1;
            break;
        }
        C[i] = I[j];
        i += 1;
    }
    while (i < 64){
        if (M[w] == '\0'){
            while (i < 64){
                C[i] = '0';
                i += 1;
            }
            break;
        }
        C[i] = M[w];
        i += 1;
        w += 1;
    }
    j = 0;
    for (i = 0;i < 16;i++){

        b = (C[i*4] - '0') * 8 + (C[i*4 + 1] - '0') * 4 + (C[i*4 + 2] - '0') * 2 + C[i*4] - '0';
        D[j] = L[b];
        j += 1;
    }
}

int main()
{
    char input[100], I[8], D[16], *end;
    int n, type, i, j;
    double N;
    while(scanf("%s", input) != EOF){
        memset(I, '\0', 8);memset(D, '\0', 16);
        type = 0;
        for (i = 0;input[i] != '\0';i++){
            if (input[i] == '.'){
                type = 1;
                break;
            }
        }
        switch (type){
            case 0:
                n = atoi(input);
                inttoHEX(n, I);
                if (n < 0){
                    for (j = 0;j < 8;j++){
                            if (I[j] == '\0'){
                                I[j] = 'f';
                            }
                    }
                }else{
                    for (j = 0;j < 8;j++){
                            if (I[j] == '\0'){
                                I[j] = '0';
                            }
                    }
                }
                for (j = 0;j < 4;j++){
                    printf("%c%c ", I[2*j + 1], I[2*j]);
                    if (j == 3){
                        printf("\n");
                    }
                }
                break;
            case 1:
                N = strtod(input, &end);
                doubletoHEX(N, D);
                for (j = 7;j >= 0;j--){
                    printf("%c%c ", D[2*j], D[2*j + 1]);
                    if (j == 0){
                        printf("\n");
                    }
                }
        }
    }
    return 0;
}