#include <stdio.h>
#include <math.h>

int main()
{
    long long int x,y;
    scanf("%ld %ld", &x, &y);
    x = abs(x);
    y = abs(y);
    if(x == 0 && y == 0 ) printf("0\n");
    else if((x+y)%2LL == 0)  printf("-1\n");
    else 
    {
        double temp = log(x+y+1)/log(2);
        double k = 1.0;
        while( (k-42.0)<0 )
        {
        if((temp-k+1)>0 && (k-temp)>=0) break;
        else k+=1.0;
        }
        printf("%d\n", (int)k);
    }
    return 0;

}