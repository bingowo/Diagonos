#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ts(char *s)
{
    int len=strlen(s),i,all=0,x,n,bei,j2=0;
    int t[24];
    char jj[4];
    for(i=0;i<len;i++)
    {
        all=all*pow(2,8)+s[i];
    }
    if(len==1)
        all*=pow(2,4);
    else if(len==2)
        all*=pow(2,2);
    for(i=0;all>0;i++)
    {
        if((all|1)==all)
            t[i]=1;
        else
            t[i]=0;
        all=all>>1;
    }
    n=i;
    for(i=0;i<n;)
    {
        bei=1;
        x=0;
        for(int j=0;j<6&&i<n;j++)
        {
            x+=t[i]*bei;
            bei*=2;
            i++;
        }
        jj[j2]=ch(x);
        j2++;
    }
    jj[j2]='\0';
    for(i=j2-1;i>=0;i--)
    {
        printf("%c",jj[i]);
    }
    if(len==1)
        printf("==");
    else if(len==2)
        printf("=");
}
int ch(int x)
{
    char c;
    if(x<26)
        c='A'+x;
    else if(x>=26&&x<52)
        c='a'+x-26;
    else
        c='0'+x-52;
    return c;
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char sa[101],s[4];
        int i,j;
        gets(sa);
        for(i=0;i<strlen(sa);)
        {
            for(j=0;j<3&&i<strlen(sa);j++,i++)
            {
                s[j]=sa[i];
            }
            s[j]='\0';
            ts(s);
        }
        printf("\n");
    }
    return 0;
}
