#include <stdio.h>

int main()
{
    int t , n , r;
    scanf("%d",&t);
    int a[100] , i = 0 , cnt;
    for(int j = 0; j < t; j++)
    {
        scanf("%d %d",&n,&r);
        if(r <= 10)
        {
            do
            {
                a[i++] = n % r;
                n = n/r;
            }while(n != 0);

            cnt = i;

        }

        for(i=0; i < cnt; i++ ) printf("%d",a[i]);
        printf("%d\n",a[cnt]);
    }






    return 0;
}


