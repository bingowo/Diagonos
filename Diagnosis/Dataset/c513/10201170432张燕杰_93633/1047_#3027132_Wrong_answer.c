#include<stdio.h>

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i = 0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[501] = {'\0'};
        gets(s);
        char temp;
        char*p = s;
        int count = 1;
        while(*p != 0)
        {
            temp = *p;
            p++;
            if(temp == *p)
            {
                count++;
                if(count == 255)
                {
                    printf("%d%c",count,temp);
                    count = 1;
                }
                continue;
            }
            else{
                printf("%d%c",count,temp);
                count = 1;
            }
        }

        printf("\n");
    }
    return 0;
}
