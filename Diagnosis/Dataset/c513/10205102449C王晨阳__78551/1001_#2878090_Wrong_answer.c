#include<stdio.h>

void change(int n,int r){
    int k=n%r;//余数
    int m=n/r;
    if(m!=0){
        change(m,r);
    }
    if(k<=9){
        printf("%d",k);
    }
    else{
        printf("%c",'A'-10+k);
    }
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        int n,r;
        scanf("%d,%d\n",&n,&r);
        change(n,r);
        printf("\n");
    }
    return 0;
}