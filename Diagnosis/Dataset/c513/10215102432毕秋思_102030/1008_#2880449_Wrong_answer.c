#include <stdio.h>
int main()
{
    int n1=0,n2=0,t=0,count=0,T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d\n",&n1,&n2);
        t=n1^n2;
        while(t!=0)
        {
            count++;
            t=t&(t-1);
        }
        printf("%d\n",count);
    }
    return 0;
}
