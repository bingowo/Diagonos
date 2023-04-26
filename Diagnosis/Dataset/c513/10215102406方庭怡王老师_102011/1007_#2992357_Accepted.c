#include <stdio.h>

int max_len_dif(long long a)
{
    int fir = a % 2,sec;
    int count = 1;
    int temp = 1;
    while(a)
    {
        a >>= 1;
        sec = a % 2;
        if(sec != fir)
        {temp++;}
        else
        {
            if(temp > count)
                {count = temp;}
            temp = 1;
        }
        fir = sec;
    }
    if(temp > count){count = --temp;}
    return count;
}


int main()
{
    int total;
    scanf("%d",&total);
    for(int i = 0; i < total; i++)
    {
        int a;
        scanf("%d",&a);
        printf("case #%d:\n",i);
        printf("%d\n",max_len_dif(a));
    }
    return 0;
}
