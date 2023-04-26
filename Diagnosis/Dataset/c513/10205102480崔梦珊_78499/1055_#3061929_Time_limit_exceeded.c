#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[1000000]={0};
    scanf("%s",s);
    int alpha[200];
    for(int j=0;j<200;j++) alpha[j]=-1;
    int len=0,pos=0,lentemp=0;
    int str_len=strlen(s);
    for(int i=0;i<str_len;i++)
    {
        /*printf("%c  %d ",s[i],alpha[s[i]]);
        printf("i:%d  lentemp:%d  pos:%d\n",i,lentemp,pos);*/
        if(alpha[s[i]]<0)
        {
            lentemp++;
        }
        else
        {
            if(lentemp>len)
            {
                len=lentemp;
                pos=i-len;
            }
            i=alpha[s[i]];
            for(int j=0;j<200;j++) alpha[j]=-1;
            lentemp=0;
            /*alpha[s[i]]=i;*/
        }
        alpha[s[i]]=i;
        /*printf("i:%d  lentemp:%d  pos:%d\n",i,lentemp,pos);*/
    }
    if(lentemp>len)
    {
        len=lentemp;
        pos=str_len-len;
    }
    for(int i=pos;i<pos+len;i++)
    {
        printf("%c",s[i]);

    }

}
