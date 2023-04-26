#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char word [30];
}STRUCT;      //不要忘了定义

int cmp(const void *a,const void *b)
{
    STRUCT *x =(STRUCT*)a;
    STRUCT *y =(STRUCT*)y;
    return strcmp(x->word,y->word);
}





int main()
{
    int T,i,len;
    scanf("%d",&T);
    getchar();   //把回车符放入缓冲区
    for(i=0;i<T;i++){
        char s[505];
        gets(s);            //其他字符都读入，到回车停止读入
        len=strlen(s);
        STRUCT n [300];//定义结构体数组

        int j,r,t;
        for(r=0,t=0,j=0;j<len;j++){    //把数组输入到结构体
             if(s[j] == ' ' ||s[j] == ',' || s[j] == '.' || s[j] == '!' || s[j] == '?')
            {
                n[r].word[t] = '\0';  //表示单词结束
                t=0;
                r++;
            }
            else
            {
                n[r].word[t] = s[j];
                t++;
            }
        }

        qsort(n,r,sizeof(STRUCT),cmp);


        printf("case #%d:\n",i);                  //输出
        char mark[50];
        memset(mark,0,sizeof(mark));

        for(int index = 0;index < r+1;index++)
        {
            if(strcmp(n[index].word,mark) == 0)//与mark相等，输出下一个
            {
                continue;
            }

            else
            {
                printf("%s ",n[index].word);
                strcpy(mark,n[index].word);
            }
        }
        printf("\n");






    }


}
