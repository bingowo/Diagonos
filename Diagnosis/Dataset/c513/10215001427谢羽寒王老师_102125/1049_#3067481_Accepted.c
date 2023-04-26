#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char words[50];
}STRUCT;

int cmp(const void*a,const void*b)
{
    STRUCT *x = (STRUCT*)a;
    STRUCT *y = (STRUCT*)b;
    return strcmp(x->words,y->words);
}

int main()
{
    int T;//问题数
    scanf("%d",&T);
    getchar();
    for(int i=0 ; i < T ;i++)    //进入一个问题
    {
        printf("case #%d:\n",i);
        char o[501];
        gets(o);
        int len;
        len=strlen(o);
        STRUCT n[300];//定义结构体数组

        int j,r,t;
        for(j=0,r=0,t=0;j<len;j++)  //读入数组
        {
            if(o[j] == ' ' || o[j] == ',' || o[j] == '.' || o[j] == '!' || o[j] == '?')
            {
                n[r].words[t] = '\0';  //表示单词结束
                t=0;
                r++;
            }
            else
            {
                n[r].words[t] = o[j];
                t++;
            }
        }
        n[r].words[t] = '\0';

        qsort(n,r,sizeof(STRUCT),cmp);

        char mark[50];
        mark[0]='\0';

        for(int index = 0;index < r+1;index++)
        {
            if(strcmp(n[index].words,mark) == 0)//与mark相等，输出下一个
            {
                continue;
            }

            else
            {
                printf("%s ",n[index].words);
                strcpy(mark,n[index].words);
            }
        }
        printf("\n");
    }
    return 0;
}
