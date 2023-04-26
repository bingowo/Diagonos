#include <stdio.h>
#include <stdlib.h>
int main(){
    int t,i=0;
    scanf("%d",&t);
    while(i<t){
    printf("case #%d",i);
    printf(":\n");
    i++;
    int n;
    scanf("%d",&n);
    int a[40];
    int cal = 0,sign = 0;
    for(int k = 0;n;k++){
        a[k] = n%2;
        n /= 2;
        if(n){
            if(a[k] != n%2){
                 sign++;
                if(cal<sign)
                    cal = sign;
            }
               else
                sign = 0;
        }
    }
    printf("%d\n",cal+1);
        }
return 0;
}
