#include <stdio.h>
#include <stdlib.h>

void chuli(char s[],char re[][85])
{
    int len=strlen(s),i,j,hang=85;
    re[hang][0]=s[0];
    for(i=1;i<len;i++)
    {
        if(s[i]>s[i-1])
        {
            hang--;
            for(j=0;j<i;j++)
            {
               if(re[hang][j]==0) re[hang][j]=' ';
            }
            re[hang][i]=s[i];
            re[hang][i+1]=0;
        }
        else if(s[i]<s[i-1])
        {
            hang++;
            for(j=0;j<i;j++)
            {
                if(re[hang][j]==0) re[hang][j]=' ';
            }
            re[hang][i]=s[i];
            re[hang][i+1]=0;
        }
        else
        {
            for(j=0;j<i;j++)
            {
                if(re[hang][j]==0) re[hang][j]=' ';
            }
            re[hang][i]=s[i];
            re[hang][i+1]=0;
        }
    }
}

int main()
{
    while(1)
    {
        int i,j,co=0;
        char s[90];
        gets(s);
        if(strlen(s)<=0) break;
        char re[170][85];
        for(i=0;i<170;i++)
        {
            for(j=0;j<85;j++)
            {
                re[i][j]=0;
            }
        }
        chuli(s,re);
        for(i=0;i<170;i++)
        {
            if(strlen(re[i])>0) printf("%s\n",re[i]);
        }
    }
    return 0;

}
