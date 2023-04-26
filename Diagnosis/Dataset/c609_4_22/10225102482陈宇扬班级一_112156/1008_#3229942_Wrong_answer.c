#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    while ((scanf("%s", s)) != EOF)
    {
        char *point = strchr(s, '.');
        if (point == NULL) //整型
        {
            int n1 = atoi(s);
            int sizei = sizeof(n1);
            unsigned char *p1 = (unsigned char *)&n1; //点睛之笔， 关键
            for (int j = 0; j < sizei; j++)           //只控制次数
                printf("%02x ", *p1++);
        }
        else //浮点型
        {
            double n2 = atof(s);
            int sizef = sizeof(n2);
            unsigned char *p2 = (unsigned char *)&n2;
            for (int j = 0; j < sizef; j++)
                printf("%02x ", *(unsigned char *)p2++);
        }
        printf("\n");
    }
    return 0;
}
