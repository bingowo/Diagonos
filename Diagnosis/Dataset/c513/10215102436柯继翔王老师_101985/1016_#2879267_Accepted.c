#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    char s[20];
    int k = 0;
    while(n != 0){
        int x = n % r;
        if(x < 0)x = x - r;
        if(x >= 10 ){
            s[k++] = x - 10 + 'A';
        }else{
            s[k++] = x + '0';
        }
        n = (n - x) / r;
    }
    for(int i = k - 1;i >= 0;i--){
        printf("%c",s[i]);
    }
    if(k == 0){
        printf("0");
    }
    return 0;
}
