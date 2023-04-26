#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int alpha[130];
typedef struct string 
{
    char st[100];
}s;


int cmp(const void* q1, const void* q2)
{
    s * p1 = (s *) q1;
    s * p2 = (s *) q2;
    int len1 = strlen(p1->st);
    int len2 = strlen(p2->st);
    int len = (len1 > len2) ? len1 : len2;
    for(int i = 0; i < len; i++)
    {
        if(p1->st[i] != p2->st[i])
            return (alpha[p1->st[i]] - alpha[p2->st[i]]);
    }
    return(len1 - len2);
}


int main()
{
    char c = getchar();
    while(c != EOF)
    {
        //放
        s str[100]={0};
        for(int i = 0; i < 52; i += 2)
        {
            alpha[c] = i;
            alpha[c + 'a' - 'A'] = i + 1;
            c = getchar();
            
        }
        
        
        c = getchar();
        
        
        int n = 0;
        int n_len = 0;
        while(c != '\n' && c != EOF)
        {   
            if(c == ' ')
            {
                c = getchar();
                n++;
                n_len = 0;
                continue;
            }
            if(c == '\n' || c == EOF)
            {
                continue;
            }

            str[n].st[n_len++] = c;
            c = getchar();//最后一个是/n或者eof
        }
        n++;//注意+1哦
        //排序
        qsort(str,n,sizeof(s),cmp);

        //输出
        for(int i = 0; i < n - 1; i++)
        {
            printf("%s ",str[i].st);
        }

        printf("%s\n",str[n-1].st);
        
        if(c == '\n')
        c = getchar();//注意+1哦
    }
    return 0;
}
