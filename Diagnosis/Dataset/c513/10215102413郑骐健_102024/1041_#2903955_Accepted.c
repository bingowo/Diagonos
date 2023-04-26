#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{

    char c = 0,c_=0;
    int n=1;
    int max =0;
    c_ = getchar();
    while((c =getchar())!=EOF&&c!='\n')
    {
        if(c!=c_)
        {
            n++;
            c_=c;
        }

        else
        {
            max = (max<n)?n:max;
            n=1;
        }
    }
    max = (max<n)?n:max;
    printf("%d",max);
    return 0;
}
