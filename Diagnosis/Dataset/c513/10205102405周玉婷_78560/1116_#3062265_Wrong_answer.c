#include <stdio.h>
#include <math.h>

int main()
{
    int x,y;
    scanf("%d%d", &x, &y);
    x = abs(x);
    y = abs(y);
    if(x == 0 && y == 0 ) printf("0\n");
    else if((x+y)%2 == 0)  printf("-1\n");
    else 
    {
        double temp = log(x+y+1)/log(2);
        double k = 1;
        while(k < 42)
        {
        if((temp-k+1)>0 && (k-temp)>=0) break;
        else k+=1;
        }
        printf("%d\n", (int)k);
    }
    return 0;

}