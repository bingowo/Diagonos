#include <stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    char table[]="0123456789ABCDEFGHIJKLMNOPORSTUVWXYZ";
    for(int i=0;i<T;i++)
    {
        int N,R;
        scanf("%d%d",&N,&R);
         int k=0,a[33],sign=1;
         if(N<0) {sign=-1;N=-N;}
         do{
            int r=N%R;
            a[k++]=table[r];
            N=N/R;
            }while(N);
            if(sign<0) printf("-");
            for(k=k-1;k>=0;k--) printf("%c",a[k]);
            printf("\n");
        }
    return 0;
}
