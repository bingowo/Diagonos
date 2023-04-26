#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[1000000]={0};
    scanf("%s",s);
    int alpha[200]={-1};
    int len=0,pos=0,lentemp=0;
    int str_len=strlen(s);
    for(int i=0;i<str_len;i++)
    {
        if(alpha[s[i]]==-1)
        {
            lentemp++;
            alpha[s[i]]=i;
        }
        else
        {
            if(lentemp>len)
            {
                len=lentemp;
                pos=alpha[s[i]];
            }
            for(int j=0;j<200;j++) alpha[j]=-1;
            lentemp=1;
            alpha[s[i]]=i;
        }
    }
    if(lentemp>len)
    {
        len=lentemp;
        pos=alpha[s[str_len-len]];
    }
    for(int i=pos;i<pos+len;i++)
    {
        printf("%c",s[i]);

    }

}
