#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    while(1)
    {
    	scanf("%d",&a);
        if(a==0)
        {
            break;
        }
        else
        {
            printf("%d\n",(int)pow(10,a*log10(a)-(int)(a*log10(a))));
        }
    }
    return 0;
}