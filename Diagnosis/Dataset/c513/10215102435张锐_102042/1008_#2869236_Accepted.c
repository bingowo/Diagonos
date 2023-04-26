#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int or,and;
        or=x|y;and=x&y;
        int more=0,less=0;
        while(or)
        {
            if(or&1) more++;
            or>>=1;
        }
        while(and)
        {
            if(and&1) less++;
            and>>=1;
        }
        int a=more-less;
        printf("%d\n",a);
    }
    return 0;
}
