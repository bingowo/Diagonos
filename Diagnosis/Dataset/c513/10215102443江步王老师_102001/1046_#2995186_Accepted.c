#include<stdio.h>
#include<ctype.h>
#include<string.h>

char *a[6]={"the","a","an","of","for","and"};

typedef struct a
{
    char str[101];
}words;

int main()
{
    int i,j;
    int t;
    char s[101];
    scanf("%d\n",&t);

    for (i=0;i<t;++i)
    {
        gets(s);
        char *p=s;
        int cnt=0;
        words w[101];
        //读取该行并储存单词
        while (*p)
        {
            int len=0;
            char t[101];
            //实现提取单词，单词存放在临时数组t中
            if (isalpha(*p))
            {
                if (isupper(*p)) (*p)+=32;
                while ((*p)!=' ' && (*p)!=0)
                {
                    if (isupper(*p)) (*p)+=32;
                    *(t+len)=*p;
                    p++;len++;       
                }
                if ((*p)==' ') p++;
                *(t+len)=0;
            }
            len=0;
            //进行第一轮检查
            for (j=0;j<6;++j)
            {
                if (strcmp(t,a[j])==0) break;
            }
            if (!(j>=6))
            {
                continue;
            }
            else
            {
                if (!cnt)
                {
                    strcpy(w[cnt++].str,t);
                }
                else
                {
                    for (j=0;j<cnt;++j)
                    {
                        if (strcmp(w[cnt].str,t)==0)
                        {
                            break;
                        }
                    }
                    if (!(j>=cnt)) continue;
                    else
                    {
                        strcpy(w[cnt++].str,t);
                    }
                }
            }
        }
        
        //output
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
    }
    return 0;
}