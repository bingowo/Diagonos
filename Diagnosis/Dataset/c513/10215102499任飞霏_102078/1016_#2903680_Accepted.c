#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int n,t;
    int a[30],i=0;
    scanf("%d%d",&n,&t);
    if(n==0)printf("0");
    else{
        while(n){
        if(n%t < 0){
            a[i]=n-(n/t+1)*t;
            n = n/t+1;
        }
        else{
            a[i] = (n%t);
            n /= t;
        }
        i++;
        }
        for(int j = i - 1;j >= 0;j--){
            printf("%c",table[a[j]]);
        }
    }
    return 0;
}
