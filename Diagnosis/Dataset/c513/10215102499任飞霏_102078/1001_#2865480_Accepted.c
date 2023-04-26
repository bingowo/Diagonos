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
        int c = 0,a[100];
        while(n != 0){
            a[c] = n%r;
            c++;
            n/=r;

        }
        for(int j = c - 1;j >= 0;j--){
            if(a[j] >= 10){
                printf("%c",a[j] - 10 + 'A');
            }
            else
                printf("%d",a[j]);
        }
        printf("\n");
    }while(number--);
    return 0;
}
