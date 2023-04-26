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
    if(N<0){
        trans(N/R,R);
        print(N%R);
    }
}


int main() {
    int N,R;
    
        scanf("%d %d",&N,&R);
        trans(N,R);
    return 0;
}
