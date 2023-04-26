#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500
void input(int*A,int*B,char*a,char*b);
void sub(int*A,int*B);
void output(int*A);
int main()
{
    int A[L]={0};int B[L]={0};
    char a[L]={0};char b[L]={0};
    while(scanf("%s %s",a,b)!=EOF)
    {
        input(A,B,a,b);
        sub(A,B);
        output(A);
    }
    return 0;
}
void input(int*A,int*B,char*a,char*b)
{
   int n,m,i,k;
   n=strlen(a);
   m=strlen(b);
   for(i=L-1,k=n-1;k>=0;i--,k--)
    {
       A[i]=a[k]-'0';

    }

    for(i=L-1,k=m-1;k>=0;i--,k--)
    {
        B[i]=b[k]-'0';
    }
}
void sub(int*A,int*B)
{
    int i,k,n,j;
    for(i=L-1;i>=0;i--)
    {
        if(A[i]<B[i])
        {
           for(k=i-1;i>=0;k--)
           {
               if (A[k]>0) break;
           }
           A[k]--;
           for(j=k+1;j<i;j++)
           {
                A[j]=9;
           }
           A[i]+=10;
           A[i]-=B[i];
        }
        else A[i]-=B[i];

    }


}
void output(int*A)
{
    int i=0;
    while(A[i]==0)i++;
    for(int k=i;i<L;i++)printf("%d",A[k]);
    printf("\n");
}
