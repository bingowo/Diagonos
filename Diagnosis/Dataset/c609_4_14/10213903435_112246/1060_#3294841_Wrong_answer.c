#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[220];
    scanf("%s",s);
    char r[220];
    strcpy(r,s);
    int i,j;
    if(s[1])
    {
        for(i=0,j=0;s[i+1];i++,j++)
        {
            if(s[i]<s[i+1])
            {
                r[++j]=s[i];
                r[j+1]=0;
                strcat(r,s+i+1);
            }
            else if(s[i]==s[i+1])
            {
                int k=i+1;
                for(;s[i]==s[k];k++);
                if(s[k]>s[i])
                {
                    int t=0;
                    for(;t<2*(k-i)-1;t++)
                    {
                        r[++j]=s[i];
                    }
                    r[j+1]=0;
                    strcat(r,s+k);
                }
                i=k;
            }
            else continue;
        }
    }
    else printf("%s",s);
    printf("%s",r);
    return 0;
}
