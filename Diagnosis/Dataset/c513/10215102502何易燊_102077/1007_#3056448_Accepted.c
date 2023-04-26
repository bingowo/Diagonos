#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        int last = -1;
        int max = 0;
        int rec = 0;
        while (num>0)
        {
            if ((num&1)!=last) rec++;
            else
            {
                if (rec>max) max = rec;
                rec = 1;
            }
            last = num&1;
            num >>= 1;
        }
        if (rec>max) max = rec;
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}