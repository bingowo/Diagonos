#include <stdio.h>
#include <stdlib.h>

long long tili(long long chang,long long kuan)
{
    long long re;
    if(chang==kuan)
    {
        return chang*4;
    }
    else if(chang>kuan)
    {
        chang-=kuan;
        return kuan*4+tili(chang,kuan);
    }
    else return tili(kuan,chang);
    
}

int main()
{
    long long chang,kuan,re;
    scanf("%lld%lld",&chang,&kuan);
    re=tili(chang,kuan);
    printf("%lld",re);
    return 0;

}
