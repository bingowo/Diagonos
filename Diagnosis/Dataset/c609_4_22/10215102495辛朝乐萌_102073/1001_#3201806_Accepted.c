#include <stdio.h>

void print(int num)
{
    if(num<10){
        printf("%d",num);
    }
    else{
        printf("%c",num-10+'A');
    }
}

void trans(N,R)
{
    if(N>0){
        trans(N/R,R);
        print(N%R);
    }
}


int main() {
    int t;
    int N,R;
    scanf("%d",&t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d",&N,&R);
        if(N<0) {
            printf("-");
            N=-N;
        }
        trans(N,R);
        printf("\n");
    }
    return 0;
}



