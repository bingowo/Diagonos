#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,n,r;
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&number);
    do{
        scanf("%d%d",&n,&r);
        if(n < 0){
            printf("-");
            n = -n;
        }
        int c = 0,a[35];
        while(n){
            a[c] = (n%r);
            c++;
            n /= r;
        }
        for(int i = c - 1;i >= 0;i--){
           printf("%c",table[a[i]]);
        }
        printf("\n");
    }while(number--);
    return 0;
}