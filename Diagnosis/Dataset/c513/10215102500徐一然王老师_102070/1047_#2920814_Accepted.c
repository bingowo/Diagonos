#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

int main()
{
    int count,count1,num=0;
    scanf("%d\n",&count);
    count1=count;
    char S[501];
    char *p1=S;
    char copy;
    while(count--)
    {
        gets(S);
        copy=*p1;
        printf("case #%d:\n",count1-count-1);
        while(*p1)
        {
            if(*p1==copy)
            {
                num++;
                p1++;
            }
            else
            {
                if(num>255)
                {
                    printf("%d%c%d%c",255,copy,num-255,copy);
                    copy=*p1;
                    num=0;
                }
                else
                {
                    printf("%d%c",num,copy);
                    copy=*p1;
                    num=0;
                }

            }
            if(p1-S==strlen(S))
            {
                if(num>255)
                {
                    printf("%d%c%d%c\n",255,copy,num-255,copy);
                copy=*p1;
                num=0;
                }
                else
                {
                    printf("%d%c\n",num,copy);
                copy=*p1;
                num=0;
                }

            }
        }
        p1=S;

    }
}
