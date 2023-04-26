#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int i,j,l1,l=0;
    for(i=0;s[i];i++)
    {
        if(s[i]<48||s[i]>57);
        if(s[i]=='0');
        else
        {
            if(s[i]>=48&&s[i]<=57)
        {
            l1=1;
            for(j=i+1;s[j];j++)
            {
                if(s[j]>=48&&s[j]<=57)
                    l1=l1+1;
                else
                    break;
            }
            l=(l1>l)?l1:l;
            i=j;
        }
        }
    }
    printf("%d",l);
}