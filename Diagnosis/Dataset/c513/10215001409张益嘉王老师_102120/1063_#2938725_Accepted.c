#include <stdio.h>
#include <stdlib.h>

long long tili(long long chang,long long kuan)
{
    long long re,yu;
    if(chang<kuan) return(kuan,chang);
    else
    {
        yu=chang%kuan;
        if(yu==0) return chang/kuan*kuan*4;
        else return chang/kuan*kuan*4+tili(kuan,yu);

    }
}

int main()
{
    long long chang,kuan,re;
    scanf("%lld%lld",&chang,&kuan);
    re=tili(chang,kuan);
    printf("%lld",re);
    return 0;

}
