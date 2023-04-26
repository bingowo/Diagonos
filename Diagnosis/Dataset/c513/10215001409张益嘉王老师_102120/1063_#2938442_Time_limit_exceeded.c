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
        re=kuan*4;
    }
    else
    {
        kuan-=chang;
        re=chang*4;
    }
    return re+tili(chang,kuan);
}

int main()
{
    long long chang,kuan,re;
    scanf("%lld%lld",&chang,&kuan);
    re=tili(chang,kuan);
    printf("%lld",re);
    return 0;

}
