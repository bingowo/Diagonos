#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int r[4]={0,0,0,0},i,tem;
    char s[3],t[20],temp[20];
    while(scanf("%s %s",s,t)!=EOF)
    {
        switch(s[0])
        {
            case'I':
            {
                tem=strlen(t);
                int k=0;
                for(i=3;i<tem;i++)
                {
                    temp[k++]=t[i];
                }
                temp[k]='\0';
                r[t[0]-'A']=atoi(temp);
                break;
            }
            case'M':
            {
                if(s[1]=='O')
                {
                    r[t[0]-'A']=r[t[3]-'A'];
                    break;
                }
                else
                {
                    r[t[0]-'A']*=r[t[3]-'A'];
                    break;
                }
            }
            case'A':
            {
                r[t[0]-'A']+=r[t[3]-'A'];
                break;
            }
            case'S':
            {
                r[t[0]-'A']-=r[t[3]-'A'];
                break;
            }
            case'D':
            {
                r[t[0]-'A']/=r[t[3]-'A'];
                break;
            }
            case'O':
            {
                printf("%d\n",r[t[0]-'A']);
                break;
            }
        }
    }
    return 0;
}
