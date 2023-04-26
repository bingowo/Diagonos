#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int clean (char *s)
{
    char t[52][102]={};
    int len=0,num=0;
    for (int i=0;i<strlen(s);i=len+i+1)
    {
        len=0;
        for (int j=i+1;j<strlen(s);j++)
        {
            if (s[j]==s[i]) len++;
            else break;
        }
        if (len) continue;
        t[0][num++]=s[i];
    }
    for (int k=0;k<50;k++)
    {
        len=0,num=0;
        for (int i=0;i<strlen(t[k]);i=len+i+1)
        {
            len=0;
            for (int j=i+1;j<strlen(t[k]);j++)
            {
                if (t[k][j]==t[k][i]) len++;
                else break;
            }
            if (len) continue;
            t[k+1][num++]=t[k][i];
        }
    }
    return strlen(s)-num;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int q=0;q<T;q++)
    {
        char s[102]={},t[310][102]={};
        scanf("%s",s);
        int max=0,len=strlen(s),temp=0,j=0;
        for (int i=0;i<=len;i++)
        {
            for (char c='A';c<='C';c++)
            {
                t[j][i]=c;
                for (int k=0;k<0;k++)
                    t[j][k]=s[k];
                for (int k=i+1;k<len+1;k++)
                    t[j][k]=s[k-1];            //insert

                temp=clean(t[j++]);
                if (temp>max) max=temp;
            }
        }
        printf("%d",max);
    }

    return 0;

}
