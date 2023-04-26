#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,n,r;
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
            if(a[i] >= 10){
                printf("%c",a[i] - 10 + 'A');
            }
            else
                printf("%d",a[i]);
        }
        printf("\n");
    }while(number--);
    return 0;
}
