#include<stdio.h>
#define L 500

void input(int A[]);

void add(int A[], int B[], int C[], int N);

void output(int A[], int N);

int main()
{
    int A[2*L+1] = {0}, B[2*L+1] = {0},
    C[2*L+1] = {0}, N;

    input(A);
    input(B);
    scanf("%d", &N);

    add(A, B, C, N);

    output(C, N);

    return 0;
}

void input(int A[])
{
    static char s[L+1];
    scanf("%s", s);
    int i=0, j, k;
    while(s[i]!='\0' && s[i]!='.') i++;

    for(j=i-1, k=L; j>=0; j--, k--)
        A[k] = s[j] - '0';

    for(j=i+1, k=L+1; j<strlen(s); j++, k++)
        A[k] = s[j] - '0';
}

void add(int A[], int B[], int C[], int N)
{
    int i;
    for(i=2*L; i>L+N; i--)
    {
        C[i] += A[i] + B[i];

        if(C[i]>=10)
        {
            C[i] -= 10;
            C[i-1] += 1;
        }
    }
    if(C[L+N+1]>=5) C[L+N] += 1;
    for(i=L+N; i>0; i--)
    {
        C[i] += A[i] + B[i];

        if(C[i]>=10)
        {
            C[i] -= 10;
            C[i-1] += 1;
        }
    }
}

void output(int C[], int N)
{
    int i = 0;
    for(; i<=L; i++)
    {
        if(C[i]!=0) break;
    }
    
    if(i>L) putchar('0');

    for(; i<=L; i++)
    {
        putchar(C[i] + '0');
    }

    putchar('.');

    for(; i<=L+N; i++)
    {
        putchar(C[i] + '0');
    }

    putchar('\n');
}