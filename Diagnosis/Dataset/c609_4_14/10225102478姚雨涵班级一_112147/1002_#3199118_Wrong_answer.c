#include <stdio.h>
#include <stdlib.h>
int main(){
    int t,i=0;
    scanf("%d",&t);
    while(i<t){
    int n,cal,sign,j = 0;
    cal = sign = 0;
    printf("case #%d",i);
    printf(":\n");
    i++;
    scanf("%d",&n);
    int a[40];
    int* p = a;
    for(;n > 0;j++){
        a[i] = n%2;
        n /= 2;
    }
    for(int k = 0;k < j;k++){
        if(*p == *(p++))
            sign++;
        else
            sign = 0;
        if(sign > cal)
            cal = sign;
    }
printf("%d\n",cal);}
return 0;
}
