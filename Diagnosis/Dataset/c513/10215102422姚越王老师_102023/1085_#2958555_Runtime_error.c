#include<stdio.h>
#include<string.h>
void sub(int *A,const int* B)
{
    int i,j,k,tmp;
    for(i=509;i>-1;--i)
    {
        if(A[i]<B[i])
        {
            k=i;
            while(!A[i--]);
            A[i]--;for(j=i+1;j<k;++j)A[j]=9;
            tmp=10+A[j]-B[j];A[j]=tmp;
            i=j;
        }
        else A[i]-=B[i];
    }
}
int compare(int *A,int* B)
{
    int i=0;
    while(A[i]==B[i])i++;
    if(A[i]>=B[i])return 1;
    return 0;
}
int main()
{
    char A[510],B[510];
    while(~scanf("%s %s",A,B))
    {
        int Ax[510]={0},Bx[510]={0},flag;
        int lena=strlen(A),lenb=strlen(B);
        int i,j;
        for(i=510-lena,j=0;j<lena;j++,i++)Ax[i]=A[j]-48;
        for(i=510-lenb,j=0;j<lenb;j++,i++)Bx[i]=B[j]-48;
        flag=compare(Ax,Bx);
        if(flag)//a>=b
        {
            sub(Ax,Bx);
            for(i=0;i<510;++i)if(Ax[i])break;
            if(i==510)printf("0");
            for(i;i<510;++i)printf("%d",Ax[i]);
            printf("\n");}
        else
        {
            sub(Bx,Ax);
            for(i=0;i<510;++i)if(Bx[i])break;
            printf("-");for(i;i<510;++i)printf("%d",Bx[i]);
            printf("\n");
        }
    }
    return 0;
}