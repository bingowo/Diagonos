#include <stdio.h>

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

int main(){
    int num,now=0;
    int n,p,m,t;
    scanf("%d",&num);
    while(now<num){
        scanf("%d %d %d %d",&n,&p,&m,&t);
        printf("%d\n",times(n,p,m,t));
        now++;
    }
    return 0;
}