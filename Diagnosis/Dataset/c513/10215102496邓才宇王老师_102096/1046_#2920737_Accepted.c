#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    char a[6][10]={"the","a","an","of","for","and"};
    for(int i=0;i<T;i++)
    {
        char s[101];
        gets(s);
        char s1[101][101];
        int x=0,y=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]!=' ')
            {
                if(s[j]<'a') s1[x][y++]=s[j]+32;
                else s1[x][y++]=s[j];
            }
            else
            {
                s1[x][y]='\0';
                x++;
                y=0;
            }
        }
        s1[x][y]='\0';
        x++;
        int num=0;
        for(int k=0;k<x;k++)
        {
            int q;
            for(q=0;q<6;q++)
            {
                if(strcmp(s1[k],a[q])==0){num++;}
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",x-num);
    }
}
