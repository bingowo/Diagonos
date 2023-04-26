#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char digit;
    int len;
}STRUCT;


int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char origin[505];
        gets(origin);
        STRUCT WAY[505];
        
        char mark;
        mark = '\0';
        int j;
        int r=0;
        
        for(int l=0;l<strlen(origin);l++)
        {
            WAY[l].len = 1;
        }
            
        for(j=0;j<strlen(origin);j++)
        {
            if(origin[j] == mark)//如果与mark相等
            {
                WAY[r].len++;
            }
            else
            {
                r++;
                WAY[r].digit = origin[j];
                mark = origin[j];
                
            }
        }
        
        for(int k=0;k<r+1;k++)//输出
        {
            if(WAY[k].len<256)
            {
                printf("%d\'%c\''",WAY[k].len,WAY[k].digit);
            }
            else
            {
                int temp = WAY[k].len;
                while(temp > 255)
                {
                    printf("255\'%c\'",WAY[k].digit);
                    temp = temp - 255;
                }
                if(temp > 0)
                    printf("%d\'%c\'",WAY[k].len,WAY[k].digit);
            }
            
        }
        printf("\n");
        
    }
    return 0;
}
