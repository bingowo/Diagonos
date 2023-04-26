#include <stdio.h>
#include<string.h>

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
    int j[26];
    for(int n=0,i=0;i<26;n++){
        if(isprime(n)){
            j[i]=n;i++;
        }
    }
    for(int i=0;i<26;i++)printf("%d ",j[i]);
}