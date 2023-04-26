#include <stdio.h>
#include <stdlib.h>
int numerator[100];
int denominator[100];
int maxi_find(int a,int b){
    if(a > b){
        ;
    }else if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }else if(a ==b){
        return a;
    }
   for (int i = a;i>0;i++){
       if(i%a == 0 && i% b == 0){
           return i;
       }
   }
   return 0;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int ttl = 0;
    scanf("%d",&ttl);
    for (int i = 0; i < ttl;i++){
        scanf("%d",&numerator[i]);
        char c;
        scanf("%c",&c);
        scanf("%d",&denominator[i]);
    }
    int maxi = 1;
    for(int j = 0; j < ttl;j++){
        if (j ==0 ){
            maxi = maxi_find(denominator[0],denominator[1]);
        }else if(j>1){
            maxi = maxi_find(maxi,denominator[j]);
        }
    }
    int numeratorsum = 0;
    for (int k = 0; k < ttl;k++){
        int tomuti = maxi/denominator[k];
        numerator[k] = tomuti*numerator[k];
        numeratorsum+= numerator[k];
    }
    int gcdnum = gcd(numeratorsum,maxi);
    numeratorsum = numeratorsum/gcdnum;
    maxi = maxi/gcdnum;
    printf("%d""/""%d",numeratorsum,maxi);




   // pr
   // intf("%d",maxi);
//    for(int j = 0; j < ttl;j++){
//        printf("%d ",numerator[j]);
//        printf("%d \n",denominator[j]);
//    }
//
}