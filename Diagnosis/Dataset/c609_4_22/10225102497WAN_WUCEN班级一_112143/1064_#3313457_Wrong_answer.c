#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct
    {
        int a;
        int b;
        long long int circumference;//
    }Rectangle;
    Rectangle rt={0,0,0};
    scanf("%d%d",&rt.a,&rt.b);
    while(rt.a&&rt.b)
    {
        if(rt.a>=rt.b)
        {
            rt.a-=rt.b;
            rt.circumference+=4*rt.b;
        }
        else
        {
            rt.b-=rt.a;
            rt.circumference+=4*rt.a;
        }
    }
    printf("%lld",rt.circumference);
}
