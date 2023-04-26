#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
    char now,pre=0;
    int max=0,x=0;
    while((now=getchar())!='\n')
    {
        if(pre==0){x++;pre=now;continue;}
        else
        {
            if(now!=pre)x++;
            else {if(x>max)max=x;x=1;}
            pre=now;
        }
    }
    if(x>max)max=x;
    printf("%d",max);
}

