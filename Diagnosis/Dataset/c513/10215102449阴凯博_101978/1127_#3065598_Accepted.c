#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nume;
    int deno;
}FRAC;

int GCD(int m,int n)
{
    if (m<n)
        return GCD(n,m);
    else
    {
        if (m%n==0)
            return n;
        else return GCD(m%n,n);
    }

}

int LCM(int m,int n)
{
    return (m*n/GCD(m,n));

}

FRAC pluss(FRAC A,FRAC B)
{
    FRAC N;
    N.nume=A.deno*B.nume+A.nume*B.deno;
    N.deno=A.deno*B.deno;
    int m=GCD(N.nume,N.deno);
    N.nume=N.nume/m;
    N.deno=N.deno/m;
    return N;
}

int main()
{
    int n;
    scanf("%d",&n);
    FRAC* arr=(FRAC*)malloc(n*sizeof(FRAC));
    for (int i=0;i<n;i++)
    {
        scanf("%d/%d",&arr[i].nume,&arr[i].deno);
    }
    FRAC R=arr[0];
    for (int i=1;i<n;i++)
        R=pluss(R,arr[i]);
    if (R.deno==1)
        printf("%d\n",R.nume);
    else
        printf("%d/%d\n",R.nume,R.deno);
    return 0;
}
