#include<stdio.h>
typedef struct
{
    int num;
    int times;
}huiwen;
int main()
{
    huiwen hw;
    int ans,sna=0,len=0;
    scanf("%d",&hw.num);
    ans=hw.num;
    int i;
    while(ans>0)
    {
        sna*=10;
        sna+=ans%10;
        ans/=10;
    }
    while(sna!=hw.num)
    {
        ans=hw.num;
        sna=0;
        while(ans>0)
        {
            sna*=10;
            sna+=ans%10;
            ans/=10;
        }
        hw.times++;
    }
    printf("%d %d",hw.times,hw.num);
    return 0;
}