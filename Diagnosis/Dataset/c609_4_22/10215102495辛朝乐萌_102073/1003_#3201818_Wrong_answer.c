#include <stdio.h>
#include <stdlib.h>


void change(long long a)
{
    if(a>0)
    { change(a/2333);
      printf("%d ",a%2333);
    }
}

int main()
{
    int t;
    long long num;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%lld",&num);
            change(num);
        printf("\n");
    }
    return 0;
}
