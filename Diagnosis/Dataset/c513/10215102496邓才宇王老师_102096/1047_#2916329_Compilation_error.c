#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[501];
        scanf("%s",s);
        int num=1;
        printf("case #%d:\n",i);
        if(strlen(s)==1) printf("%d%c",1,s[0]);
        
        for(int i=0;i<strlen(s)-1;i++)
        {
            if(s[i]==s[i+1])
            {
                num++;
                if(i==strlen(s)-2&&num!=strlen(s)) printf("%d%c",num,s[i]);
            }
            if(num==255)
            {
                printf("%d%c",255,s[i]);
                num=0;
            }
            if(s[i]!=s[i+1])
            {
                printf("%d%c",num,s[i]);
                num=1;
                if(i==strlen(s)-2)
            {
                printf("%d%c",1,s[i+1]);
                flag=1;
            }
            }
            if(num==strlen(s))
            {
                printf("%d%c",num,s[0]);
            }
            }
        printf("\n");
    }
}
