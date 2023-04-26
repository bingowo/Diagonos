#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0; cas<T; cas++)
    {
        double stack[101];
        int index=0;
        int i=0;
        char s[101][11];
        char ch;
        double y;
        while(1)
        {
            scanf("%s",s[i++]);
            scanf("%c",&ch);
            if(ch=='\n') break;
        }
        for(int j=i-1; j>=0; j--)
        {
            if(s[j][0]=='+')
            {
                y=stack[index-1]+stack[index-2];
                index-=2;
                stack[index++]=y;
            }
            else if(s[j][0]=='-')
            {
                y=stack[index-1]-stack[index-2];
                index-=2;
                stack[index++]=y;
            }
            else if(s[j][0]=='*')
            {
                y=stack[index-1]*stack[index-2];
                index-=2;
                stack[index++]=y;
            }
            else if(s[j][0]=='/')
            {
                y=stack[index-1]/stack[index-2];
                index-=2;
                stack[index++]=y;
            }
            else
            {
                stack[index++]=atof(s[j]);
            }
        }
        printf("case #%d:\n",cas);
        printf("%.6f\n",stack[--index]);
    }
    return 0;
}
