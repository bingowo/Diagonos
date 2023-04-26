#include <stdio.h>
#include <stdlib.h>

void maxlendif(long long int n)
{
    int former,latter;
    former=n%2;
    int count=1,temp=1;
    while(n)
    {
        n=n>>1;
        latter=n%2;
        if(former!=latter)
        {
            temp++;
        }
        else{
            if(temp>count)
            {
                count=temp;
                temp=1;
            }
        }
        former=latter;
    }
    if(temp>count){
        count=temp-1;
    }
    printf("%d\n",count);

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        long long int n;
        scanf("%lld",&n);
        maxlendif(n);
    }
    return 0;
}
