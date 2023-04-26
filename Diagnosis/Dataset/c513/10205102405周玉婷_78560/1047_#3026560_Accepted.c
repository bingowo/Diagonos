#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int j=0; j<t; j++)
    {
        c=getchar();
        char temp = c;
        int len=1;
        printf("case #%d:\n",j);
        while(c != '\n')
        { 
            c=getchar();
            if(temp == c)
            len++;
            else
            {
                if(len > 255)
                {
                int num=len%255;
                printf("%d%c%d%c",255,temp,num,temp);
                }
                else
                printf("%d%c",len,temp);
                temp=c;len=1;
            }
        }
        printf("\n");
    }
    return 0;
}