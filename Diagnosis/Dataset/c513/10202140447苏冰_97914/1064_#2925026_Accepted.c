#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
double stack[101];
int main()
{
    int T;
    scanf("%d",&T);
    char s[101][12];char c;
    for(int cas=0;cas<T;cas++)
    {
        int top=-1;
        int i=0;double f1,f2;
        for(i=0;;i++)
        {
            scanf("%s%c",s[i],&c);
            if(c=='\n') break;
        }
        for(int j=i;j>=0;j--)
        {
            switch(s[j][0])
            {
                case('+'):f1=stack[top--];f2=stack[top--];stack[++top]=f1+f2;break;
                case('-'):f1=stack[top--];f2=stack[top--];stack[++top]=f1-f2;break;
                case('*'):f1=stack[top--];f2=stack[top--];stack[++top]=f1*f2;break;
                case('/'):f1=stack[top--];f2=stack[top--];stack[++top]=f1/f2;break;
                default:stack[++top]=atof(s[j]);break;
            }
        }
        printf("case #%d:\n",cas);
        printf("%.6f\n",stack[top]);
    }
    return 0;
}
