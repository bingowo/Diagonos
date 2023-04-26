#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        unsigned x;
        scanf("%u",&x);
        int last=x%2;
        x=x/2;
        int a=1,b=1;
        int naxt;
        while(x>0)
        {
            naxt=x%2;
            x=x/2;
            if(last==naxt)
            {
                last=naxt;
                break;
            }
            if(last!=naxt)
            {
                last=naxt;
                a+=1;
            }
        }
        while(x>0)
        {
            naxt=x%2;
            x=x/2;
            if(last==naxt)
            {
                last=naxt;
                b=1;
            }
            if(last!=naxt)
            {
                last=naxt;
                b+=1;
            }
            if(a<b) a=b;
        }
        printf("case #%d:\n%d\n",i,a);
    }
    return 0;
}

