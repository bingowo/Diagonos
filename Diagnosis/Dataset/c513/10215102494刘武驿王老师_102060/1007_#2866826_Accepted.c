int len(long long a)
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
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        printf("case #%d:\n%d\n",i,len(a));
    }
}