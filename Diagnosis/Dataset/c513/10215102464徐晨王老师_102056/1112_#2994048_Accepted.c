#include <stdio.h>
#include <stdlib.h>

int sum=0;

void f4(int n4){
    for(int i=0;;i++){
        if((n4-i*4)>=0)f3(n4-i*4);
        else return;
    }
}

void f3(int n3){
    for(int i=0;;i++){
        if((n3-i*3)>=0)f2(n3-i*3);
        else return;
    }
}

void f2(int n2){
    for(int i=0;;i++){
        if((n2-i*2)>=0)f1(n2-i*2);
        else return;
    }
}

void f1(int n1){
    if(n1>=0)sum++;
    else return;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        f4(n);
        printf("%d\n",sum);
        sum=0;
    }
}
