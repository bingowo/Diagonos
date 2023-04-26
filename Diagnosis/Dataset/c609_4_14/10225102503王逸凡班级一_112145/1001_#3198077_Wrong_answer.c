#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    int T;
    scanf("%d",&T);
    for(int con=0;con<T;con++){
        int N,R;
        int i=0;
        scanf("%d %d",&N,&R);
        char r[100];
        if(N<0){
            r[i]='-';
            N=-N;
            i++;
        }
        do{
            r[i]=table[N%R];
            i++;
            N=N/R;

        }while(N!=0);
        int j;
        for(j=i-1;j>=0;j--){
            printf("%c",r[j]);
        }
        printf("\n");
        }



    return 0;
}
