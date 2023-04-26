#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        long long int x;
        scanf("%d",&x);
        long long int last=x%2;
        x=x/2;
        int a=1,b=1;
        long long int naxt;
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
                if(a<b) a=b;
                b=1;
                continue;
            }
            if(last!=naxt)
            {
                last=naxt;
                b+=1;
            }
        }
        printf("case #%d:\n%d\n",i,a);
    }
    return 0;
}
