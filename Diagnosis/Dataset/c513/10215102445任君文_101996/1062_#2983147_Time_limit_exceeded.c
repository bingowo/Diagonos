#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
long step(int n)
{
    if(n==1)
        {return 1;}
    else if(n==2)
        {return 2;}
    else if(n==3)
        {return 4;}
    else if(n==4)
        {return 8;}
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