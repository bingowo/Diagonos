#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int map[26];
typedef struct{
        char s[21];
        }ch;

void creatmap(char s[])
{
    char *p=s,index=0;
    while(*p)
    {
        map[*p-'A']=index;
        p++;
        index++;
    }
}
int cmp(const void*a,const void*b)
{
    ch* x=(ch*)a;
    ch* y=(ch*)b;
    char*xx=x->s,*yy=y->s;
    for(;toupper(*xx)==toupper(*yy);xx++,yy++);
    if(!*xx)return -1;
    else if(!*yy)return 1;
    else return map[toupper(*xx)-'A']-map[toupper(*yy)-'A'];

}
int main(void)
{
       char temp[27];
        scanf("%s",temp);
        creatmap(temp);

        ch ans[101];
        char c=getchar();
        int line=0,index=0;
        while((c=getchar())!=EOF)
        {
            if(c==' ')
            {
                ans[line].s[index]='\0';
                line++;
                index=0;
            }
            else if(c=='\n')
            {
                ans[line].s[index]=='\0';
                qsort(ans,line+1,sizeof(ans),cmp);
                for(int i=0;i<=line;i++)
                {
                    printf("%s%c",ans[i].s,(i==line)?'\n':' ');
                }
                scanf("%s",temp);
                creatmap(temp);
                c=getchar();
                line=0;
                index=0;
                
            }
            else
            {
                ans[line].s[index]=c;
                index++;
            }

        }


   return 0;

}
