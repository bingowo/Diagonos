#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    double freq[26];
    char array[100];
}DATA;

int cmp(const void *a , const void *b)
{     //频率降序，ascii降序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    
    if(x->freq != y->freq)
        return (x->freq - y->freq);
    else
        return ( ((x->array)-'A') - ((y->array)-'A') );
}

int main()
{
    int T;
    scanf("%d",&T);            //输入问题数
    DATA tests[T];             //定义结构体数组
    int index,i,j,r;
    
    for(index = 0;index < T;index++)  //第index个问题
    {
        for(i = 0;i<26;i++)
            scanf("%lf",&tests[index].freq[i]);
        //读入字母的频率
        
        scanf("%s",tests[index].array);   //读入需要排序的字符串
        
        int k = strlen(tests[index].array);
        printf("case #%d:\n",index);
        
        qsort(tests[index].array , k , sizeof(char) , cmp);
        
        
        printf("%s\n",tests[index].array);
    }
    
    return 0;
}