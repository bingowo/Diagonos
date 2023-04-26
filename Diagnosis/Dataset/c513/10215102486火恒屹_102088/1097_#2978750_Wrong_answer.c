#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c;
    c=getchar();
    char s[101][81];
    int i=0;
    while(c!=EOF)
    {
        ungetc(c,stdin);
        scanf("%s",&s[i]);
        i++;
        int height[81]={0};
        int nowh=81;
        int max=81;
        int min=81;
        for(int j=1;j<strlen(s[i]);j++)
        {
            if(s[i][j]>s[i][j-1]) nowh++;
            if(s[i][j]<s[i][j-1]) nowh=nowh-1;
            height[j]=nowh;
            if(nowh>max) max=nowh;
            if(nowh<min) min=nowh;
        }
        for(int j=max;j>=min;j=j-1)
        {
            for(int k=0;k<strlen(s[i]);k++)
            {
                if(height[k]==max)
                    printf("%c",s[i][k]);
                else printf("%c",32);
            }
            printf("%c",10);
        }
        c=getchar();
    }
    return 0;
}
