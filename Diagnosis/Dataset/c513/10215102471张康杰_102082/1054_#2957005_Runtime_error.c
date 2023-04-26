#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char temp[71][36];
        int M,current_length = 0,count_word = 0;
        scanf("%d",&M);
        printf("case #%d:\n",i);
        while(scanf("%s",temp[count_word]) && getchar() != '\n')
        {
            if(current_length + strlen(temp[count_word]) + count_word <= M)
            {
                current_length = strlen(temp[count_word]) + current_length;
                count_word++;
            }
            else
            {
                int gap = M - current_length;
                int average = gap/(count_word - 1);
                int remainder = gap - average*(count_word - 1);
                for(int j = 0;j < count_word - remainder - 1;j++)
                {
                    printf("%s",temp[j]);
                    for(int k = 0;k < average;k++)
                    {
                        putchar(' ');
                    }
                }
                for(int j = count_word - remainder - 1;j < count_word - 1;j++)
                {
                    if(remainder == 0)
                        break;
                    printf("%s",temp[j]);
                    for(int k = 0;k < average + 1;k++)
                    {
                        putchar(' ');
                    }
                }
                printf("%s\n",temp[count_word - 1]);
                strcpy(temp[0],temp[count_word]);
                count_word = 1;
                current_length = strlen(temp[0]);
            }
        }
        for(int j = 0;j < count_word + 1;j++)
        {
            printf("%s%c",temp[j],(j == count_word)?'\n':' ');
        }
        
    }
}