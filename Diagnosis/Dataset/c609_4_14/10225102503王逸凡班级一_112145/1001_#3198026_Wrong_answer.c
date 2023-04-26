#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    int T;
    scanf("%d",&T);
    for(int con=0;con<T;con++){
        int N,R;
        scanf("%d %d",&N,&R);
        char r[100];
        int i=0;
        do{
            r[i]=table[N%R];
            i++;
            N=N/R;

        }while(N!=0);

        for(int j=0;j<i;j++){
            printf("%c",r[j]);
        }
        }



    return 0;
}