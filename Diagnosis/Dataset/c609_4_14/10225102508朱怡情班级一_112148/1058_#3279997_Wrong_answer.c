#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void f(int n)
{
    if(n!=0){
        if(n%(-2)>=0){
                f(n/(-2));
                printf("%d",n%(-2));
        }
        else{
                f(n/(-2)+1);
                printf("%d",n-(n/(-2)+1)*(-2));
        }
    }
}

int main()
{
    int n;
    scanf("%d%d",&n);
    if(n!=0)f(n);
    else printf("0");
    return 0;
}

