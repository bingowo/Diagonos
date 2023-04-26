#include <stdio.h>
#include <stdlib.h>
void f(int n,int r);
int main()
{undefined
    int n,r;
    while(scanf("%d %d", &n, &r)!=EOF)
    {undefined
        f(n,r);
        printf("\n");
    }
    return 0;

}
void f(int n,int r)
{undefined
    if(n==0)
        printf("0");
    else
    {undefined
        f(n/r,r);
        printf("%d",n%r);
    }
}