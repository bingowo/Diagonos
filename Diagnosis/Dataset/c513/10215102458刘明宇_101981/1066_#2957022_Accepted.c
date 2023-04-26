#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>



int times(int ALLf, int floor, int minute, int end)
{
    if(minute == 0 && floor == end)
    {return 1;}
    else if(minute == 0 && floor != end)
    {return 0;}

    if(floor == 1)
    {return times(ALLf,floor + 1, minute - 1,end);}
    if(floor == ALLf)
    {return times(ALLf,floor - 1, minute - 1,end);}

    return times(ALLf,floor - 1, minute - 1,end) + times(ALLf,floor + 1, minute - 1,end);
}

int main()
{
    int T;
    scanf("%d",&T);

    for(int i = 0; i < T; i++)
    {
        long long n,p,m,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);
        printf("%d",times(n,p,m,t));
        printf("\n");

    }

    return 0;
}
