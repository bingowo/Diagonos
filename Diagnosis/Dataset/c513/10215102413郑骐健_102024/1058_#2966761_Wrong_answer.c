#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long po = 0;
void push(char *p,char d)
{
    p[po++] = d;
}
void out()
{
    if(po>0)po--;
    else return;
}
int main()
{
    char *p = (char*)malloc(sizeof(char)*1e8);
    memset(p,0,sizeof(char)*1e8);
    char ch;
    int s = 1;
    int q =1;
    while((ch = getchar())!=EOF)
    {
        switch (q)
        {
            case 1:
                {
                    push(p,ch);
                    if(ch=='/')q = 2;
                    else if(ch=='"')q=6;
                    else if(ch=='\'')q=7;
                    break;
                }
            case 2:
                {
                    if(ch=='/')
                    {
                    out();q=3;
                    }
                    else if(ch=='*')

                    {
                        out();
                        q=4;
                    }
                    else
                    {
                        push(p,ch);
                        q=1;
                    }
                    break;
                }
            case 3:
                {
                    if(ch=='\n')
                    {
                        push(p,ch);
                        q = 1;
                    }
                    break;
                }
            case 4:
                {
                  if(ch=='*')
                  {
                      q=5;
                  }
                  else break;
                }
            case 5:
                {
                    if(ch=='/')q=1;
                }
            case 6:
                {
                    push(p,ch);
                    if(ch=='\\')q=9;
                    else if(ch=="\"")q = 1;
                    break;
                }
            case 7:
                {
                    push(p,ch);
                    if(ch=='\'')q=1;
                    else if(ch=='\\')q=8;
                    break;
                }
            case 8:push(p,ch);q=7;break;
            case 9:push(p,ch);q=6;break;
        }
    }
    for(long long i =0;i<po;i++)printf("%c",p[i]);
    free(p);
    return 0;
}
