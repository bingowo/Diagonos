#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char s[501];
        int len;
        char c;
        int num=1;
        scanf("%s",&s);
        len=strlen(s);
        printf("case #%d: \n",i);
        for(int j=0;j<len;j++)
        {
            c=s[j];
            if(s[j]==s[j+1])
            {
                num++;
                continue;
            }
            else 
            {
                if(num>255)
                    {
                        printf("255%c",c);
                        num-=255;
                    }
                printf("%d%c",num,c);
                num=1;
            }           
        }
        printf("\n");
    }
    return 0;
}