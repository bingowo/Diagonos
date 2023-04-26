#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{char s[82];int len;}c;
int main()
{
    char s[85];
    while(~scanf("%s",s))
    {   c *t=(c*)malloc(sizeof(c)*202);
    for(int i=0;i<202;i++)
        t[i].len=0;
        int len=strlen(s),fir=101,las=101,x=101,id=0;
        while(s[id]&&id<len)
        {
            for(int j=t[x].len;j<id;j++)
                t[x].s[j]=' ';
            while(s[id]==s[id+1])
              {t[x].s[id]=s[id];id++;}
            t[x].s[id]=s[id];t[x].s[id+1]='\0';
            t[x].len=id+1;
            id++;
            if(id==len)
                break;
            if(s[id]>s[id-1])
            {
                x--;
                if(fir>x)
                    fir=x;
            }
            else
            {
                x++;
                if(x>las)
                    las=x;
            }
        }
        for(int j=fir;j<=las;j++)
            printf("%s\n",t[j].s);
        free(t);
    }
}
