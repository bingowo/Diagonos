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
        char origin[500];
        gets(origin);
        STRUCT WAY[500];
        
        char mark;
        mark = '\0';
        int j,r;
        for(j=0,r=0;j<strlen(origin);j++)
        {
            WAY[r].len = 1;
            if(origin[j] == mark)//如果与mark相等
            {
                WAY[r].len++;
            }
            else
            {
                WAY[r].digit = origin[j];
                printf("%c\n",WAY[r].digit);
                mark = origin[j+1];
                r++;
            }
        }
        
        printf("%d\n",r);
        
    }
    return 0;
}
