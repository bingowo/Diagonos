#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define  num 10007





int main()
{


    int t ;
    scanf("%d",&t);
    getchar();
    for(int i =0;i<t;i++)
    {
        printf("case #%d:\n",i);
        char c,last=0;
        int count =0;
        while((c=getchar())!='\n')
        {
            if(last==0)
            {
                last = c;
                count++;
            }
            else if(c!=last)
            {
                if(count ==0)
                {
                    last = c;
                    count =1;
                }
                else
                {
                printf("%d%c",count,last);
                 last = c;
                 count = 1;
                }

            }
            else
            {
                count++;
            }
               if(count == 255)
            {
                printf("%d%c",count,last);
                count =0;
            }

        }
        if(count !=0)printf("%d%c",count,last);
        if(i!=t-1)printf("\n");
    }

    return 0;
}
