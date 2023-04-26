#include <stdio.h>



void exchange(int n,int r)
{
    int m;
    if(n)
    {
        exchange(n/r,r);
        m=n%r;
        if(m>=10)
        {
           char c=m+55;
           printf("%c",c);
        }
        else{
            printf("%d",m);
        }
    }

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        if(n<0)
        {
            n=abs(n);
            printf("-");
        }
        exchange(n,r);
        printf("\n");
    }
    return 0;
}