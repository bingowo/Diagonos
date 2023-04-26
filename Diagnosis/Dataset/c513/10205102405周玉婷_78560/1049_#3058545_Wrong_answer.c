#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*分割，储存，排序*/
typedef struct{
    char s[25];
} word;

int cmp(const void* pa, const void* pb)
{
    word* a = (word *)pa;
    word* b = (word *)pb;
    return strcmp(a->s , b->s);
}

int main()
{
    int t;
    scanf("%d", &t);
    char c = getchar();//吃掉\n
    
    for(int j=0; j<t; j++)
    {
    char temp[26]; int index = 0;//临时储存一个单词
    word sen[300]; int len = 0;//储存多个单词
    for(c = getchar(); c != '\n'; c = getchar())
    {
        if(c==' '|| c=='.' || c=='!' || c=='?'|| c==',')//分割单词
        {
           temp[index] = '\0';//结束这个单词
           int flag = 1;
           for(int i=0; i<len; i++)//判断之前是否有相等的单词
           {
            if(!strcmp(temp, sen[i].s)) 
            {flag = 0; break;}
           }

           if(flag==0) index = 0;//是重复单词，清空temp
           else //是新单词，储存
           {
            strcpy(sen[len++].s, temp);
            index = 0;//清空temp
           }
        }
        else temp[index++] = c;
    }
    qsort(sen, len, sizeof(word), cmp);

    printf("case #%d:\n", j);
    for(int i=0; i<len; i++)
    {
        printf("%s ",sen[i].s);
    }
    printf("\n");
    }
    return 0;
}