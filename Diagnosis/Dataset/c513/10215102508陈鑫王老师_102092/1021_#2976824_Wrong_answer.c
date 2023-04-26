#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int map[26];
typedef struct{
        char s[30];
        }ch;

void creatmap(char s[])
{
    char *p=s;
    int index=1;
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
    char*pa=x->s,*pb=y->s;
    for(;toupper(*pa)==toupper(*pb);pa++,pb++);
    if(!*pa)return -1;
    else if(!*pb)return 1;
    else return map[toupper(*pa)-'A']-map[toupper(*pb)-'A'];

}
int main(void)
{
       char temp[27];
        scanf("%s",temp);
        creatmap(temp);
        char c=getchar();
        ch ans[100];
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
                qsort(ans,line+1,sizeof(ch),cmp);
                for(int i=0;i<line+1;i++)
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
