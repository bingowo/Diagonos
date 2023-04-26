#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[501],flag;
        gets(s);
        int len=strlen(s),num=0,i;
        for(i=0;i<len;i++)
        {
            if(num==0)
                flag=s[i];
            while(s[i]==flag&&num<255)
            {
                num++;
                i++;
            }
            i--;
            printf("%d%c",num,s[i]);
            num=0;
        }
        printf("\n");
    }
    return 0;
}
