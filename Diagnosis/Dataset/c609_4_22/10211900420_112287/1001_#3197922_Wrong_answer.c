#include<stdio.h>
int main()
{
    char b[100],a[35]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int n,x,i,T,N,R;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        n=0;
        scanf("%d %d",&N,&R);
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        while(N!=0)
        {
            x=N%R;
            N=N/R;
            b[n]=a[x];
            n++;
        }
        for(n=n-1;n>=0;n--)
        {
            printf("%c",b[n]);
        }
        printf("\n");
    }
    return 0;

}
