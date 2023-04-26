#include <stdio.h>
#include<string.h>
#include<math.h>

int isprime(int n){
    int ret=1;
    int i=3;
    if(n==1)ret=0;
    else if(n==2)ret=1;
    else if(n%2==0)ret=0;
    else {
        while(i<sqrt(n)+1){
            if(n%i==0){
                ret=0;
                break;
            }
            i+=2;
        }
    }
    return ret;
}
int main(){
    int p[25],j[25],i;
    char c=',';
    for(i=0;i<25&&c==',';i++)scanf("%d%c",&j[i],&c);
    scanf("%d",&j[i]);
    for(int n=0,i=0;i<25;n++)
        if(isprime(n)){
            p[i]=n;i++;
        }

}