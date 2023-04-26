#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
void atob(int a,int t[])
{
    int b,i;9
    for(i=0;a!=0;i++)
    {
        b=a%2;
        t[i]=b;
        a/=2;
    }
    t[i]=2;
}

int tmax(int a)
{
    int b[100],i,flag=1,I,sum=0;atob(a,b);
    for(I=0;b[I]!=2;I++)
    {
        for(i=I;b[i]!=b[i+1]&&b[i]!=2&&b[i+1]!=2;i++) flag+=1;
        if(flag>sum) sum=flag;
    }
    return sum;
}

int main()
{
    int N,A[100],i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    for(i=0;i<N;i++)
    {
        printf("case #%d\n",i);
        printf("%d\n",tmax(A[i]));
    }
    return 0;
}
