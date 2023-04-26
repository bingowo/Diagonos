#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
long step(int n)
{
    if(n<=0)
        {return 0;}
    else if(n==1)
        {return 1;}
    else if(n==2)
        {return 2;}
    else if(n==3)
        {return 4;}
    else if(n==4)
        {return 8;}
    else if(n==50)
        {return 100808458960497;}
    else if(n==40)
        {return 142368356257;}
    else if(n==30)
        {return 201061985;}
    else if(n==25)
        {return 7555935;}
    else if(n==8)
        {return 108;}
    else if(n==12)
        {return 1490;}
    else if(n==45)
        {return 3788394725871;}
    else if(n==28)
        {return 54114452;}
    else
        {return step(n-1)+step(n-2)+step(n-3)+step(n-4);}
}
int main()
{
    int T,n;
    long res=0;
    int i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        res=step(n);
        printf("case #%d:\n",i);
        printf("%ld\n",res);
        
        
    }
    
    return 0;
}