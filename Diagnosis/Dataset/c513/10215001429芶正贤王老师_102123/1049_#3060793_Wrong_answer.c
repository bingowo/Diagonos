#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char words[50];
}STRUCT;

int cmp(const void*a,const void*b)
{
    return strcmp( (char *)a , (char *)b );
}
    
int main()
{
    int T;//问题数
    scanf("%d",&T);
    for(int i=0 ; i < T ;i++)    //进入一个问题
    {
        printf("case #%d:\n",i);
        char orgin[505];
        gets(orgin);
        STRUCT TABLE[300];//定义结构体数组
        
        for(int j=0,r=0,t=0;j<strlen(orgin);j++)  //读入数组 
        {
            if(orgin[j] == ' ' || orgin[j] == ',' || orgin[j] == '.' || orgin[j] == '!' || orgin[j] == '?')
            {
                t=0;
                r++;
            }
            else
            {
                TABLE[r].words[t] = orgin[j];
                t++;
            }
        }
        printf("1");
        qsort(TABLE,300,sizeof(STRUCT),cmp);
        printf("%s",TABLE[0].words);
        
        
        for(int index = 1;index < 300;index++)
        {
            char mark[50];
        	for(int q=0;q<50;q++)
            	mark[q] = TABLE[0].words[q];
            
            if(strcmp(TABLE[index].words,mark) == 0)//与mark相等，输出下一个
            {
                for(int q=0;q<50;q++)
            		mark[q] = TABLE[index+1].words[q];
            }
                
            else
            {
                printf(" %s",TABLE[index].words);
                for(int q=0;q<50;q++)
            		mark[q] = TABLE[index].words[q];
            }
            printf("\n");
        }
        return 0;
    }
    
    
}



