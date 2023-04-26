#include <stdio.h>
#include <stdlib.h>
int main(){
    int t,i=0;
    scanf("%d",&t);
    while(i<t){
    printf("case #%d",i);
    printf(":\n");
    i++;
    int n,j,k,sign,cal =0;
    scanf("%d",&n);
    
    do{
    k=n%2;
    j = (n / 2) % 2;
    if(j != k){
        sign++;
        if(sign > cal)
            cal = sign;
    }
    else
        sign = 0;
    n/=2;
}while(n>0);
j = k = 0;
printf("%d\n",cal);}
return 0;
}
