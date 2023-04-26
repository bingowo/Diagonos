#include <stdio.h>
#include <math.h>

int main()
{   int i=0,y,t,x;

 
    char z[10]={'0'};
    scanf("%d%d",&x,&y);
    while(x!=0);
    {
        t=x%y;
        if(t<10)
        {
            z[i]=t+'0';

        }
        else
        {
           z[i]=t-10+'A';
        }
        x=x/y;
        i++;
    }
    for(i=0;z[i];i++)
    {
        printf("%c",z[i]);
    }
    return 0;
}
