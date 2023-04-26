#include <stdio.h>
#include <stdlib.h>

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
    int n=0;
    int a[1000];
    while(N>0){
        a[n++]=N%R;
        N=N/R;
    }
    for(int i=n;i>0;i--){
        print(a[i]);
    }
    
}

int main()
{
    int N,R;
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&N,&R);
        if(N<0){
            printf("-");
            N=-N;
        }
        division(N,R);
        printf("\n");
    }
    return 0;
}
