#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        char input[501];
        int count = 1;
        scanf("%s",input);
        int len = strlen(input);
        printf("case #%d:\n",i);
        for(int j = 1;j < len;j++)
        {
            if(input[j] == input[j - 1])
            {
                count++;
            }
            else
            {
                while(count > 255)
                {
                    printf("255%c",input[j - 1]);
                    count -= 255;
                }
                printf("%d%c",count,input[j - 1]);
                count = 1;

            }
                
        }
        putchar('\n');
    }
}