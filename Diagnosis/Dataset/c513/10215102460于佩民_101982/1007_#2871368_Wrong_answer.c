#include <stdio.h>

int main(){
    int num,a=0,b,number,first,second;
    scanf("%d",&num);
    while(a<num){
        scanf("%d",&b);
        first=b%2;
        while(b!=0){
            second=b%2;
            b/=2;
            if(first!=second) { number++; }
            if(first==second);
            first=second;
        }
        printf("case #");
        printf("%d:\n",a);
        printf("%d",number);
        a++;
    }
    return 0;}