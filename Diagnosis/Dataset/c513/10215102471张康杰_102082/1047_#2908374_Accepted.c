#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int main()
    {
        int T,i;
        scanf("%d",&T);
        int count = 1;
        for(i = 0;i < T;i++)
        {
            char input[501];
            scanf("%s",input);
            int len = strlen(input);
            printf("case #%d:\n",i);
            if(len == 1)
            {
                printf("1%c\n",input[0]);
                continue;
            }
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
                    if(j == len - 1)
                    {
                        printf("1%c",input[len - 1]);
                    }
                    count = 1;

                }
                    
            }
            if(count != 1)
            {
                while(count > 255)
                {
                    printf("255%c",input[len - 1]);
                    count -= 255;
                }
                printf("%d%c",count,input[len - 1]);
            }
            count = 1;
            putchar('\n');
        }
    }