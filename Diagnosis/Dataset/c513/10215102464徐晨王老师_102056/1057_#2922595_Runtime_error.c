#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 2000
int list[N]={0};
int main(){
    char a;
    a=getchar();
    a=toupper(a);
    int n=1000,s=1000;
    list[n]=a;
    while(a=getchar()){
        a=toupper(a);
        if(a<list[n]){
            s=s+1;
            list[s]=a;
        }
        else {
            n=n-1;
            list[n]=a;
        }
    }
    for(int i=0;i<N;i++){
        if(list[i]!=0)printf("%c ",list[i]);
    }
    return 0;
}