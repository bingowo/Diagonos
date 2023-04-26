#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
typedef unsigned long long ull;

int a,b;

char Itoc(int i){
    if(i<10) return i+'0';
    return i-10+'A';
}

void Fun(int x){
    if(!x) return;
    int c=x%b;
    x/=b;
    if(c<0){
        c-=b;
        x+=1;
    }
    Fun(x);
    printf("%c",Itoc(c));
}

int main(){
    scanf("%d%d",&a,&b);
    Fun(a);
    printf("\n");


    return 0;
}
