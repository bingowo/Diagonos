#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,n,r;
    char table[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    scanf("%d",&number);
    for(int i=0;i<number;i++){
        scanf("%d%d",&n,&r);
        if(n<0){
            n=-n;
            printf("-");
        }
        char a[30]={0};
        int j=0;
        while(n){
            a[j++]=table[n%r];
            n/=r;
        }
        for(int k=j-1;k>=0;k--){
            printf("%c",a[k]);
        }
        printf("\n");
    }
    return 0;
}
