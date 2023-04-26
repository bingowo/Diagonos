#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,sum=1;
    int n,m=1;
    char s[100];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        s[0]=n%2;
        n=n/2;
        while(n)
        {
            s[m]=n%2;
            n=n/2;
            sum+=1;
            if(s[m]==s[m-1])
            {
                sum-=1;
                break;
            }
            m+=1;
        }
        printf("case #%d:\n",i);
        printf("%d\n",sum);
    }
    return 0;
}