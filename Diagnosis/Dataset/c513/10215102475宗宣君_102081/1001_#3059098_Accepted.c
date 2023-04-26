#include <stdio.h>
int main()
{
    int T,N,R,i;
    scanf("%d",&T);
    char a[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(i = 0;i<T;i++)
    {
        scanf("%d %d",&N,&R);
        int b[32],j = 0,flag = 1,k;
        if(N<0) {N = -1*N;flag = -1;}
        do
        {
            b[j++] = N%R;
            N = N/R;
        }while(N!=0);
        if(flag == -1) printf("-");
        for(k = j-1;k>=0;k--)
            printf("%c",a[b[k]]);
        printf("\n");
    }
    return 0;
}
