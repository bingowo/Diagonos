#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int T;
    scanf("%d",&T);
    char table[7][5]={"the","a","an","of","for","and"};
    for(int cas=0;cas<T;cas++)
    {
        char s[101][101];
        char ch;
        char t[101];
        int i=0;
        while(1)
        {
            scanf("%s",t);
            scanf("%c",&ch);
            int flag=0;
            for(int i=0;i<strlen(t);i++)
            {
                t[i]=tolower(t[i]);
            }
            for(int i=0;i<7;i++)
            {
                if(strcmp(t,table[i])==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) strcpy(s[i++],t);
            if(ch=='\n') break;
        }
        printf("case #%d:\n",cas);
        printf("%d\n",i);
    }
    return 0;
}
