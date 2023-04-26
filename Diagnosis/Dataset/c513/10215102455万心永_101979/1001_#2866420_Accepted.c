#include<stdio.h>

void trans(int N,int R);
int main()
{
    int n,N,R;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&N,&R);
        if (N>0)
           trans(N,R);
        else 
        {
            N=-N;
            printf("-");
            trans(N,R);
        }
        printf("\n");
    }   
    return 0;
}

void trans(int N,int R)
{
    char a[100];
    int r=0,j=0;
    do
    {
        r=N%R;
        N=N/R;
        if (r<10)
            a[j]=r+'0';
        else 
            a[j]=r-10+'A';
            j++;
    }   while(N!=0);
    for (int k=j-1;k>=0;k--)
        printf("%c",a[k]);
            
}