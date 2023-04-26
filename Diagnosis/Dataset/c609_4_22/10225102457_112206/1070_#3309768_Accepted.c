#include<stdio.h>
#include<stdlib.h>

int strn(int x, int y, int n){
    if(n == 0) return 1;
    if(x == 1 && y == 0){
        return strn(y,0,n-1);
    }
    else return strn(y,1,n-1) + strn(y,0,n-1);
}

int main(void)
{
    int n;
    while(scanf("%d",&n)){
        if(n == -1) break;
        if(n == 1) printf("2\n");
        else printf("%d\n",strn(1,0,n-2)+strn(1,1,n-2)+strn(0,1,n-2)+strn(0,0,n-2));
    }
    return 0;
}
