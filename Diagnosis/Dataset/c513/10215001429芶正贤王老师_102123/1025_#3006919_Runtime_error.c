#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    int dif;
    char  array[20];
}STRUCTURE;
    

int cmp(const void *a , const void *b)
{    //不同字符个数降序 ， 字典序排序
    STRUCTURE *x = (STRUCTURE*)a;
    STRUCTURE *y = (STRUCTURE*)b;
    
    if(x->dif != y->dif)       //不同字符串个数不同时
        return(x->dif - y->dif);   //个数多的在前面
    else                       //不同字符串个数相同时
        return strcmp(x->array , y->array);
}


int main()
{
    int T;
    scanf("%d",&T);          //问题数
    
    int index;
    for(index = 0;index < T;index++)  //进入第一个问题
    {
        int n;
        scanf("%d",&n);     //字符串个数
        
        STRUCTURE DATA[n];  //定义~
        
        int i,j,r,k;
        for(i=0;i<n;i++)              //进入第一个字符串
        {
            scanf("%s",DATA[i].array);
            
            int len;
            len = strlen(DATA[i].array);
            DATA[i].dif = len;
            
        }
        
        qsort(DATA , n , sizeof(DATA) , cmp);
        printf("case #%d:\n",index);
        for(k=0;k < n;k++)
            printf("%s\n",DATA[k].array);
    }
    return 0;
}
