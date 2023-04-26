#include <stdio.h>
#include <stdlib.h>


long long tili(long long chang,long long kuan,long long ch4,long long ku4)
{
    long long re;
    if(chang==kuan)
    {
        return ch4;
    }
    else if(chang>kuan)
    {
        chang-=kuan;
        re=ku4;
    }
    else
    {
        kuan-=chang;
        re=ch4;
    }
    return re+tili(chang,kuan,chang*4,kuan*4);
}

int main()
{
    long long chang,kuan,re;
    scanf("%lld%lld",&chang,&kuan);
    long long ch4=chang*4;
    long long ku4=kuan*4;
    re=tili(chang,kuan,ch4,ku4);
    printf("%lld",re);
    return 0;

}
