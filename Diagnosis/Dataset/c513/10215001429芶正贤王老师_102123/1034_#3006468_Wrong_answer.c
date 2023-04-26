#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    double ans[100];
    char array[100];
}DATA;

double cmp(const void *a , const void *b)
{     //频率降序，ascii降序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    
    if(x->ans != y->ans)
        return (x->ans - y->ans);
    else
        return ( ((x->array)-'A') - ((y->array)-'A') );
}

int main()
{
    int T;
    scanf("%d",&T);            //输入问题数
    DATA tests[T];             //定义结构体数组
    int index,i,j,r;
    
    double freq[26];
    
    for(index = 0;index < T;index++)  //第index个问题
    {
        for(i = 0;i<26;i++)
            scanf("%lf",&freq[i]);
        //读入字母的频率
        
        scanf("%s",tests[index].array);   //读入需要排序的字符串
        
        int k = strlen(tests[index].array);
        
        for(j=0;j<k;j++)
        {
            int tmp;
            int temp;
            tmp  = ( tests[index].array[j] - 'A' );
            temp = ( tests[index].array[j] - 'a' );
            if(tmp < 30) //大写字母
                tests[index].ans[j] = freq[tmp] ;
            else         //小写字母
                tests[index].ans[j] = freq[temp] ;
        }
        
        printf("case #%d:\n",index);
        
        qsort(tests[index].array, k , sizeof(char) , cmp);           
        printf("%s\n",tests[index].array);
    }
    
    return 0;
}