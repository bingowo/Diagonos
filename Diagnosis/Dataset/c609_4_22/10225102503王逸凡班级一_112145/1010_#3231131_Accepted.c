#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int N;
    int R;
    scanf("%d %d",&N,&R);
    char a[60000];
    int i=0;
    int y;
    do{
        y=N%R;
        N/=R;
        if(y<0){
            y=y-R;
            N+=1;
        }
        a[i]=table[y];
        i++;
    }while (N!=0);
    for(i=i-1;i>=0;i--){
        printf("%c",a[i]);
    }
    return 0;
}
