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
    if(N>0){
        division(N/R,R);
        print(N%R);
    }
}

int main()
{
    int N,R;
    int t;
    scanf("%d",&t);
    for(int i=t;i>0;i--){
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
