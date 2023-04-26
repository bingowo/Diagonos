


#include<stdio.h>
#include<stdlib.h>
int main()
{   int max(int a);
    int total,i;
    scanf("%d",&total);
    for(int i = 0; i < total; i++)
    {
       long long a,b;
       scanf("%d",&a);
    printf("case #%d:\n",i);
    b=max(a);
    printf("%d\n",b);
    }

    return 0;
}


int max(int a)
{
    int fir = a % 2,sec;
    int count = 0;
    int temp = 0;
    while(a)
    {

        a =a>> 1;
        sec = a % 2;
        if(sec != fir)
        {temp++;
            if(temp > count)
                {count = temp;}
        }
        else
        {

            temp = 0;
        }

        fir = sec;
    }



    return count;
}
