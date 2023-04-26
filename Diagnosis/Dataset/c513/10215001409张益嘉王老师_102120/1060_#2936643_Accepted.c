#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[200];
    scanf("%s",s);
    int i,j,len,re=0,co;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        co=0;
        if((s[i]<='9')&&(s[i]>'0'))
        {
            for(j=i;;j++)
            {
                if((s[j]>='0')&&(s[j]<='9')) co++;
                else break;
            }
            if(co>=re) re=co;
            i=j;
        }
    }

    printf("%d",re);
}
