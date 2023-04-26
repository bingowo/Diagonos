#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;

const int N=100;
int a,b,loc;
int as[101];

void To3(){
    int l=0;
    while(a){
        as[l]=a%3;
        l++;
        a/=3;
    }
}

void Add1(){
    for(int i=0;i<N;i++){
        as[i]+=1;
        as[i+1]+=as[i]/3;
        as[i]%=3;
    }
}

void Print(){
    int flag=0;
    for(int i=N-1;i>=0;i--){
        if(i&&i==loc){
            printf("%d",(as[i]+2)%3);
            printf(".");
            flag=1;
        }
        else if(flag||as[i]!=1){
            flag=1;
            printf("%d",(as[i]+2)%3);
        }
    }
}

int main(){
    scanf("%d%d",&a,&b);
    while(b/=3) loc++;
    To3();
    Add1();
    Print();

    printf("\n");

    return 0;
}
