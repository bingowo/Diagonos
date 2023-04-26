#include<stdio.h>
#include<string.h>
void sub(int *A,const int* B)
{
    int i,j,k;
    for(i=509;i>-1;--i)
    {
        if(A[i]<B[i])
        {
            k=i;
            while(!A[i--]);
            A[++i]--;for(j=i+1;j<k;++j)A[j]=9;
            A[j]=10-B[j];
            i=j;
        }
        else A[i]-=B[i];
    }
}
int main()
{
    char A[510],B[510];
    while(~scanf("%s %s",A,B))
    {
        int Ax[510]={0},Bx[510]={0};
        int lena=strlen(A),lenb=strlen(B);
        int i,j;
        for(i=510-lena,j=0;j<lena;j++,i++)Ax[i]=A[j]-48;
        for(i=510-lenb,j=0;j<lenb;j++,i++)Bx[i]=B[j]-48;
        sub(Ax,Bx);
        for(i=0;i<510;++i)if(Ax[i])break;
        if(i==510)printf("0");
        for(i;i<510;++i)printf("%d",Ax[i]);
        printf("\n");
    }
}