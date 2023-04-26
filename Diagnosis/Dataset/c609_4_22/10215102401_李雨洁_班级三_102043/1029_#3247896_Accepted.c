#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void F(int A[], int A_n, int B[], int B_n)
{
    int k = 0;
    int t;
    for (int i = 0; i < A_n; i++) 
    {
        for (int j = 0; j < B_n; j++) 
        {
            if (B[j] == A[i]) 
            {
                t = B[k];
                B[k] = B[j];
                B[j] = t;
                k++;
            }
        }
    }
    for (; k < B_n; k++) 
    {
        for (int z = k + 1; z < B_n; z++) 
        {
            if (B[k] > B[z]) 
            {
                t = B[k];
                B[k] = B[z];
                B[z] = t;
            }
        }
    }
}
int main()
{
    int A[500], B[500];
    int m, n;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d ", &A[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &B[i]);
    }
    F(A, m, B, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", B[i]);
    }
    return 0;
}