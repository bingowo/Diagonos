#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int n = 0;
    double m = 0;
    double t = 0;
    int temp = 0;
    int fin = 0;
    do
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        else
        {
            t = n*log10(n);
            temp = (int)t;
            m = t - temp;
            fin = (int)pow(10, m);
            while (fin >= 10)
            {
                fin = fin / 10;
            }
            printf("%d\n",fin);
        }
        
    } while (n != 0);
    
    return 0;

}