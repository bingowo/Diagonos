#include <stdio.h>
#include <stdlib.h>

int isjiangxu(char s[],int st)
{
    int len=strlen(s);
    int i;
    for(i=st;i<len-1;i++)
    {
        if(s[i]<s[i+1]) return 0;
    }
    return 1;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[30];
        char re[30];
        scanf("%s",s);
        int j,len=strlen(s);
        for(j=0;j<len;j++)
        {
            if(isjiangxu(s,j)) break;
        }
        int fi=j-1;
        if(fi==-1)
        {
            re[0]=s[len-1];
            re[1]='0';
            for(j=2;j<len+1;j++)
            {
                re[j]=s[len-j];
            }
            re[j]=0;
        }
       else if(fi==len-2)
        {
            for(j=0;j<fi;j++)
            {
                re[j]=s[j];
            }
            re[fi]=s[len-1];
            re[len-1]=s[fi];
            re[len]=0;
        }
        else
        {
            char mid;
            for(j=0;j<fi;j++)
            {
                re[j]=s[j];
            }
            for(j=len-1;j>fi;j--)
            {
                if(s[j]>s[fi]) {re[fi]=s[j];s[j]=s[fi];break;}
            }
            for(j=fi+1;j<len;j++)
            {
                re[j]=s[len+1-j];
            }
            re[j]=0;
        }
        printf("case #%d:\n%s\n",i,re);
    }
}
