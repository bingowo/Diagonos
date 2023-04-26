#include <stdlib.h>
#include <stdio.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int effi[9],j,flag = 1;
        for(j = 0;j < 9;j++)
            scanf("%d",&effi[j]);
        printf("case #%d:\n",i);
        for(j = 0;j < 9;j++)
        {
            if(j == 8)
            {
                if(effi[j] > 0)
                    putchar('+');
                else if(effi[j] == 0);
                else
                    putchar('-');
                printf("%d",effi[j]);
                continue;
            }
            if(effi[j] == 0)
                continue;
            else
            {
                if(flag)
                {
                    if(effi[j] == 1)
                        printf("x^%d",8 - j);
                    else if(effi[j] == -1)
                        printf("-x^%d",8 - j);
                    else
                        printf("%dx^%d",effi[j],8 - j);
                    flag = 0;
                }
                else
                {
                    if(effi[j] == 1)
                    {
                        if(j != 7)
                            printf("+x^%d",8 - j);
                        else
                            printf("+x");

                    }
                    else if(effi[j] == -1)
                    {
                        if(j != 7)
                            printf("-x^%d",8 - j);
                        else
                            printf("-x");
                    }
                    else
                    //printf("%c%dx^%d",(effi[j] > 0)?'+':,effi[j],8 - j);
                    {
                        if(effi[j] > 0)
                        {
                            if(j != 7)
                                printf("+%dx^%d",effi[j],8 - j);
                            else
                                printf("+%dx",effi[j]);
                        }
                        else
                        {
                            if(j != 7)
                                printf("%dx^%d",effi[j],8 - j);
                            else
                                printf("%dx",effi[j]);
                        }
                    }
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
