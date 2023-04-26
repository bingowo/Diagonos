#include <stdio.h>

int main()
{
    int T,N,R;
    scanf("%d",&T);
    int i=0;
    while(i<T)
    {
        scanf("%d %d",&N,&R);
        int sum=0;
        while(N!=0)
        {
            sum=sum*10+N%R;
            N/=R;
        }
        printf("%d",sum);
    }
    return 0;
}
