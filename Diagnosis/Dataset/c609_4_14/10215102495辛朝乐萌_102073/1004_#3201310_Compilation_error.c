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
    char s[16]={0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F};
    int b[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    char a[10000];
    scanf("%d %s %d",&N,a,&M);
    for(int i= strlen(a)-1;i>=0;i--) {
        num+=('s[i]'-'0')*t;
        t*=10;
    }
    division(num,N);
    return 0;
}