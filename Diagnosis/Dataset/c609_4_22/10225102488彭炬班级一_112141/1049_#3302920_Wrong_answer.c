#include <stdio.h>
#include <string.h>

typedef struct
{
    int n[500];
    int len;
}BigInt;

BigInt minus(BigInt A, BigInt B)
{
    BigInt D;
    int sign = 1;
    if(A.len < B.len || A.len == B.len && A.n[A.len - 1] < B.n[B.len - 1])
    {
        D = A;
        A = B;
        B = D;
        sign = -1;
    }
    int i = B.len - 1;
    for(; i >= 0; i--)
    {
        if(A.n[i] < B.n[i])
        {
            int j = 1;
            while(A.n[i + j] == 0)
            {
                A.n[i + j] = 9;
                j++;
            }
            A.n[i + j] -= 1;
            A.n[i] += 10;
        }
        A.n[i] -= B.n[i];
    }
    for(i = B.len - 1; i < A.len; i++)
    {
        if(A.n[i] < 0)
        {
            A.n[i] += 10;
            A.n[i + 1] -= 1;
        }
    }
    if(sign == -1)
        while(A.n[A.len - 1] == 0) A.len--;
    return A;
}

int main()
{
    char a[501],b[501];
    while(scanf("%s %s",a,b) != EOF)
    {
        BigInt A = {{0}, 0}, B = {{0}, 0};
        for(int i = strlen(a) - 1; i >= 0; i--)
            A.n[A.len++] = a[i] - '0';
        for(int i = strlen(b) - 1; i >= 0; i--)
            B.n[B.len++] = b[i] - '0';
        BigInt C = minus(A, B);
        int flag = 0;
        for(int i = C.len - 1; i >= 0; i--)
        {
            if(C.n[i] != 0) flag = 1;
            if(flag == 1) printf("%d",C.n[i]);
        }
        if(flag == 0) printf("0");
        printf("\n");
    }
}
