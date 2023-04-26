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
        char orgin[505];
        gets(orgin);
        STRUCT TABLE[300];//定义结构体数组
        
        int j,r,t;
        for(j=0,r=0,t=0;j<strlen(orgin);j++)  //读入数组 
        {
            if(orgin[j] == ' ' || orgin[j] == ',' || orgin[j] == '.' || orgin[j] == '!' || orgin[j] == '?')
            {
                TABLE[r].words[t] = '\0';  //表示单词结束
                t=0;
                r++;
            }
            else
            {
                TABLE[r].words[t] = orgin[j];
                t++;
            }
        }
        TABLE[r].words[t] = '\0';
        
        qsort(TABLE,r,sizeof(STRUCT),cmp);
        printf("%s",TABLE[0].words);
        
        char mark[50];
        for(int q=0;q<50;q++)
            mark[q] = TABLE[0].words[q];
        
        
        printf("\n");
    }
    return 0;
}