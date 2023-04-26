#include <stdio.h>
#include <stdlib.h>
char a[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{ int T,N,R;
scanf("%d",&T);
for(int i=0;i<T;i++)
{
    scanf("%d%d",&N,&R);
    int k=0,b[33];int n=1;
    if(N<0){n=-1;N=-N;}
    do{int r=N%R;
    b[k++]=a[r];
    N=N/R;
    }while(N);
    if(n<0)printf("-");
    for(k=k-1;k>=0;k--)
        printf("%c",b[k]);
        printf("\n");

}
return 0;
}
