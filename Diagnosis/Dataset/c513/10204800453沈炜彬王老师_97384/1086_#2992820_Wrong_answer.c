#include <stdio.h>
#include <string.h>

void input(int *A);
void sub(int *A,int *B,int N);
int cmp(int *A,int *B);

int
main()
{
    int N;
    int temp=0;
    int A[1001] = {0};
    int B[1001] = {0};
    
    input(A);
    input(B);
    scanf("%d",&N);
    printf("%d\n",cmp(A, B));
    if (cmp(A, B))
    {
        sub(A, B, N);
        while (!A[temp])
        {
            temp++;
        }
        for (int i=temp; i<=500; i++)
        {
            printf("%d",A[i]);
        }
        if (temp>500)
        {
            printf("0");
        }
        printf(".");
        for (int i=501; i<=500+N; i++)
        {
            printf("%d",A[i]);
        }
        printf("\n");
    }
    else
    {
        sub(B, A, N);
        printf("-");
        while (!B[temp])
        {
            temp++;
        }
        for (int i=temp; i<=500; i++)
        {
            printf("%d",B[i]);
        }
        if (temp>500)
        {
            printf("0");
        }
        printf(".");
        for (int i=501; i<=500+N; i++)
        {
            printf("%d",B[i]);
        }
        printf("\n");
    }
    
    return 0;
}


void
input(int *A)
{
    char c[502] = {'\0'};
    scanf("%s",c);
    int i=0;
    
    while (c[i] && c[i] != '.')
    {
        i++;
    }
    for (int j=i-1,k=500 ; j>=0; j--,k--)
    {
        A[k] = c[j] - '0';
    }
    for (int j=i+1,k=501; j<strlen(c); j++,k++) {
        A[k] = c[j] - '0';
    }
}


void
sub(int *A,int *B,int N)
{
    for (int i=1000; i>500+N; i--)
    {
        A[i] -= B[i];
        if (A[i]<0)
        {
            A[i] += 10;
            A[i-1] -= 1;
        }
    }
    if (A[500+N+1] >= 5)
    {
        A[500+N] += 1;
    }
    for (int i=500+N; i>0; i--)
    {
        A[i] -= B[i];
        if (A[i]<0)
        {
            A[i] += 10;
            A[i-1] -= 1;
        }
    }
}

int
cmp(int *A,int *B)
{
    int temp=0;
    while (A[temp]==0 && B[temp]==0)
    {
        temp++;
    }
    if (A[temp]>=B[temp])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}