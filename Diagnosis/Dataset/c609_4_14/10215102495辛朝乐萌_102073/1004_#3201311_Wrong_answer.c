#include <stdio.h>
#include <string.h>

void print(int num)
{
    if(num<10){
        printf("%d",num);
    }
    else{
        printf("%c",num-10+'A');
    }
}

void division(int N,int R)
{
    if(N>0){
        division(N/R,R);
        print(N%R);
    }
}


int main() {
    int N,M;
    int num=0;
    int t=1;
    char a[10000];
    scanf("%d %s %d",&N,a,&M);
    for(int i= strlen(a)-1;i>=0;i--) {
        num+=('a[i]'-'0')*t;
        t*=10;
    }
    division(num,N);
    return 0;
}