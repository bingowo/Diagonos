#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        unsigned int n;int count=1,maxcount=1;
        scanf("%u",&n);
        while(n/2)
        {
            if((n%2==1&&(n/2%2)==0)||(n%2==0&&(n/2%2)==1))count++;
            else
            {
                maxcount=(count>maxcount?count:maxcount);
                count=1;
            }
            n/=2;
        }
        maxcount=(count>maxcount?count:maxcount);
        printf("case #%d:\n%d\n",i,maxcount);
    }
    return 0;
}
