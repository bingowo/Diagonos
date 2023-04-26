#include <stdio.h>
#include <stdlib.h>
int main(){
    int t,i=0;
    scanf("%d",&t);
    while(i<t){
    i++;
    printf("case #%d",i,":");
    int n,j,k,sign,cal =0;
    scanf("%d",&n);
    k=n%2;
    do{
    n/=2;
    j=n%2;
    if(j != k){
        sign++;
        if(sign > cal)
            cal = sign;
    }
    else
        sign = 0;
    k = n % 2;
}while(n);
j = k = 0;
printf("%d\n",cal);}
return 0;
}
