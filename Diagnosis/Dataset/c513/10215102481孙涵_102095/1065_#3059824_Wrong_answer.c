#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    if(x == 1 || x == 2){
        printf("%d",a);
        return 0;
    }else if(x == 3){
        printf("%d",2*a);
        return 0;
    }else if(x == (n - 1)){
        printf("%d",m);
        return 0;
    }
    return 0;
}


