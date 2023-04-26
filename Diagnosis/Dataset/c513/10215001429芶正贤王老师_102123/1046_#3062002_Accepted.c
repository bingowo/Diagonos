#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct
{
    char words[500];
}STRUCT;

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char origin[105];
        gets(origin);
        STRUCT VOCAB[100];
        
        int j,r,t;
        for(j=0,r=0,t=0;j<strlen(origin);j++)  //读入数组
        {
            if(origin[j] == ' ')
            {
                VOCAB[r].words[t] = '\0';  //表示单词结束
                t=0;
                r++;
            }
            else
            {
                VOCAB[r].words[t] = tolower(origin[j]);
                t++;
            }
        }
        //此处r值正确
        
        int cnt=r+1;
        
        for(int index=0;index<r+1;index++)
        {
            if(strcmp(VOCAB[index].words,"the") == 0)
                cnt--;
            else if(strcmp(VOCAB[index].words,"a") == 0)
                cnt--;
            else if(strcmp(VOCAB[index].words,"an") == 0)
                cnt--;
            else if(strcmp(VOCAB[index].words,"of") == 0)
                cnt--;
            else if(strcmp(VOCAB[index].words,"for") == 0)
                cnt--;
            else if(strcmp(VOCAB[index].words,"and") == 0)
                cnt--;
        }
        
        printf("%d\n",cnt);
    }
    return 0;
}
