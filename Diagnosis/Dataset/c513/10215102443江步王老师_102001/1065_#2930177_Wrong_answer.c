#include<stdio.h>
#include<malloc.h>

void input_A(int *A, int n);
void input_B(int *B, int n);
void input_I(int *I,int n,int a,int b);
void input_O(int *O,int *I,int n,int b);
void input_M(int *M,int *I,int *O,int x,int a);

int main()
{
    int a,b,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int *A = (int *)malloc(sizeof(int)*(n+1));
    int *B = (int *)malloc(sizeof(int)*(n+1));
    int *I = (int *)malloc(sizeof(int)*(n+1));
    int *O = (int *)malloc(sizeof(int)*(n+1));    
    int *M = (int *)malloc(sizeof(int)*(n+1));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    input_A(A,n);
    input_B(B,n);
    b=(m-(A[n-1]-A[1])*a)/(B[n-1]-B[1]);
    input_I(I,n,a,b);
    input_O(O,I,n,b);
    input_M(M,I,O,n,a);
    if (x != n-1)
    {
        printf("%d",M[x]);
    }
    else
    {
        printf("%d",m);
    }
    
    free(A);free(B);free(I);free(O);free(M);
    return 0;
}

void input_A(int *A, int n)
{
    A[1]=1;
    A[2]=0;
    int i;
    if (n<=2)
    {
        return;
    }
    else
    {
        for (i=3;i<=n-1;i++)
        {
            A[i]=A[i-1]+A[i-2];
        }
        A[i]=0;
    }
    return;
}


void input_B(int *B, int n)
{
    B[1]=0;
    B[2]=1;
    int i;
    if (n<=2)
    {
        return;
    }
    else
    {
        for (i=3;i<=n-1;i++)
        {
            B[i]=B[i-1]+B[i-2];
        }
        B[i]=0;
    }
    return;
}


void input_I(int *I,int n,int a,int b)
{
    I[1]=a;
    I[2]=b;
    int i;
    if (n<=2)
    {
        return;
    }
    else
    {
        for (i=3;i<=n-1;i++)
        {
           I[i]=I[i-1]+I[i-2];
        }
        I[i]=0;
    }
    return;
}


void input_O(int *O,int *I,int n,int b)
{
    O[1]=0;
    O[2]=b;
    int i;
    if (n<=2)
    {
        return;
    }
    else
    {
        for (i=3;i<=n-1;i++)
        {
           O[i]=I[i-1];
        }
        
    }
    return;
}


void input_M(int *M,int *I,int *O,int n,int a)
{
    M[1]=a;
    M[2]=a;
    int i;
    if (n>=2)
    {
        for (i=3;i<=n-1;i++)
        {
            M[i]=M[i-1]+I[i]-O[i];
        }
        O[i]=M[i-1];
        M[i]=0;
    }
    return;
}