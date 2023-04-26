#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int j,p1;
        double x=0;
        char s[100];
        gets(s);
        if(s[0]>=48)
        {
            p1=1;
            for(j=0;s[j];j++)
            {
                if(s[j]=='.')
                {
                    for(j=j+1;s[j];j++)
                    {
                        x=x+(s[j]-'0')*pow(10,-1*p1);
                        p1++;
                    }
                    break;
                }
                x=10*x+s[j]-'0';
            }
            printf("case #%d:\n%lf",i,x);
        }
    }
}
