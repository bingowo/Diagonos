#include<stdio.h>
#include<ctype.h>
#include<string.h>

typedef struct Aword
{
    char s[500];
}word;

int cmp(const void *_a, const void *_b);

int main()
{
    int T;
    int i,j,k;
    int n;
    scanf("%d",&T);
    getchar();
    for (i=0;i<T;i++)
    {
        word words[501];
        char t[501];
        char str[501];
        char *p=NULL;
        gets(t);
        p=t;
        j=0;
        n=0;

        while (*p)//取单词
        {
            if (isalpha(*p))//当前所指是字符
            {
                str[j]=*p;
                j++;
                p++;
            }
            else//当前所指非字符
            {
                str[j]='\0';
                if (n>0)
                {
                    k=0;
                    while (k<n)//对已有单词进行查重
                    {
                        if (strcmp(str,words[k].s) == 0)//发现重复
                        {
                            memset(str,0,sizeof(str));//清空str
                            j=0;
                            p++;
                            break;
                        }
                        k++;
                    }
                    if (!(k<n))//未发现重复
                    {
                        strcpy(words[n].s,str);//将str中内容赋值给words[n].s
                        j=0;
                        n++;
                        p++;
                        memset(str,0,sizeof(str));
                    }
                }
                else
                {
                    strcpy(words[n].s,str);//将str中内容赋值给words[n].s
                    j=0;
                    n++;
                    p++;
                    memset(str,0,sizeof(str));
                }
            }
        }
        
        qsort(words,n,sizeof(word),cmp);

        printf("case #%d:\n",i);
        for (j=0;j<n;j++)
        {
            printf("%s ",words[j].s);
        }
        putchar('\n');
    }
    return 0;
}

int cmp(const void *_a, const void *_b)
{
    word *a = (word *)_a;
    word *b = (word *)_b;
    return (strcmp((*a).s,(*b).s));
}